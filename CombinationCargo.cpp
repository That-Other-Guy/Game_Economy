#include "CombinationCargo.hpp"
#include <sstream>

Game_Economy::Objects::CombinationCargo::CombinationCargo(
	const unsigned int& _cargo_unique_id,
	Game_Economy::TranspReq_T _transport_requirements,
	const float& _displacement_litres, 
	const float& _dry_weight_kilogramms, 
	const std::string _name, 
	const unsigned int& _item_quantity_limit, 
	const float& _mass_limit_kilogramms, 
	const float& _volume_limit_litres
)
	:
	Game_Economy::Objects::Cargo{ 
		_cargo_unique_id,
		_transport_requirements,
		_dry_weight_kilogramms, 
		_displacement_litres, 
		_name 
	},
	item_quantity_limit(_item_quantity_limit),
	mass_limit_kilogramms(_mass_limit_kilogramms),
	volume_limit_litres(_volume_limit_litres)
{
}

float Game_Economy::Objects::CombinationCargo::GetLoadedMass() const
{
	float mass_loaded_killogramms = 0.0f;
	for (const auto& cargo : contents)
	{
		mass_loaded_killogramms += cargo->GetMass().gross_kilogramms;
	}
	return mass_loaded_killogramms;
}

float Game_Economy::Objects::CombinationCargo::GetGrossWeight() const
{
	return GetLoadedMass() + gross_limit_kilogramms;
}

float Game_Economy::Objects::CombinationCargo::GetLoadedVolume() const
{
	float volume_loaded_litres = 0.0f;
	for (const auto& cargo : contents)
	{
		volume_loaded_litres += cargo->GetVolume().displacement_litres;
	}
	return volume_loaded_litres;
}

float Game_Economy::Objects::CombinationCargo::GetPercentageLoaded_Mass() const
{
	return Game_Math::Utilities::GetPercentage(GetLoadedMass(), mass_limit_kilogramms);
}

float Game_Economy::Objects::CombinationCargo::GetPercentageLoaded_Volume() const
{
	return Game_Math::Utilities::GetPercentage(GetLoadedVolume(), volume_limit_litres);
}

std::string Game_Economy::Objects::CombinationCargo::GetDetails(const std::string& _deliminator) const
{
	std::ostringstream return_stream;
	return_stream << "(" << std::to_string(GetUniqueID()) << ") " << name << "\n"
		<< "Tare Weight: " << Game_Math::Utilities::PrintFloat2(gross_limit_kilogramms)
		<< "kg Gross Weight: "
		<< Game_Math::Utilities::PrintFloat2(GetGrossWeight())
		<< "kg Displacement: "
		<< Game_Math::Utilities::PrintFloat2(displacement_litres) << "L\n";

	return_stream << "Contents: " << std::to_string(contents.size()) << "/" <<
		std::to_string(item_quantity_limit) << " Items\n\n";

	for (const auto& c : contents)
		return_stream << c->GetBriefDetails();
		
	return_stream << "\n" << "Total Load Weight: " 
		<< Game_Math::Utilities::PrintFloat2(GetLoadedMass())
		<< "/" << Game_Math::Utilities::PrintFloat2(mass_limit_kilogramms)
		<< "kg (" << Game_Math::Utilities::PrintFloat2(GetPercentageLoaded_Mass())
		<< "%) Total Load Volume: " 
		<< Game_Math::Utilities::PrintFloat2(GetLoadedVolume())
		<< "/" << Game_Math::Utilities::PrintFloat2(volume_limit_litres)
		<< "L (" << Game_Math::Utilities::PrintFloat2(GetPercentageLoaded_Volume())
		<< "%)\n";

	return return_stream.str();
}

std::string Game_Economy::Objects::CombinationCargo::GetBriefDetails() const
{
	std::ostringstream return_stream;
	return_stream << "(" << std::to_string(GetUniqueID()) << ") " << name
		<< "(" << contents.size() << " Items) Weight: "
		<< Game_Math::Utilities::PrintFloat2(GetGrossWeight()) << "kg Displacement: "
		<< Game_Math::Utilities::PrintFloat2(displacement_litres) << "L\n";
	return return_stream.str();
}

Game_Economy::CargoMass_T Game_Economy::Objects::CombinationCargo::GetMass() const
{
	float mass_loaded_killogramms = GetLoadedMass();
	return {
		mass_loaded_killogramms,
		mass_limit_kilogramms - mass_loaded_killogramms,
		mass_loaded_killogramms + gross_limit_kilogramms
	};
}

Game_Economy::CargoVolume_T Game_Economy::Objects::CombinationCargo::GetVolume() const
{
	float volume_loaded_litres = GetLoadedVolume();
	return{
		volume_loaded_litres,
		volume_limit_litres - volume_loaded_litres,
		displacement_litres
	};
}

Game_Economy::CargoItemsCount_T Game_Economy::Objects::CombinationCargo::GetItemsCount() const
{
	unsigned int items = contents.size();
	return {
		items,
		item_quantity_limit - items
	};
}

Game_Economy::CargoReturn Game_Economy::Objects::CombinationCargo::CheckForCargoItem(const unsigned int _cargo_unique_id) const
{
	for (const auto& cargo : contents)
	{
		if (cargo->GetUniqueID() == _cargo_unique_id)
			return Game_Economy::CargoReturn_T::Success;
	}
	return Game_Economy::CargoReturn_T::DoesNotExist;
}

std::pair<Game_Economy::CargoReturn, Game_Economy::CargoMass_T> 
	Game_Economy::Objects::CombinationCargo::CheckCargoItemMass(
		const unsigned int _cargo_unique_id
	)
{
	for (const auto& cargo : contents)
	{
		if (cargo->GetUniqueID() == _cargo_unique_id)
		{
			return { Game_Economy::CargoReturn_T::Success, cargo->GetMass() };
		}
	}
	return { Game_Economy::CargoReturn_T::DoesNotExist, CargoMass_T() };
}

std::pair<Game_Economy::CargoReturn, Game_Economy::CargoVolume_T> 
	Game_Economy::Objects::CombinationCargo::CheckCargoItemVolume(
		const unsigned int _cargo_unique_id
	)
{
	for (const auto& cargo : contents)
	{
		if (cargo->GetUniqueID() == _cargo_unique_id)
		{
			return { Game_Economy::CargoReturn_T::Success, cargo->GetVolume() };
		}
	}
	return { Game_Economy::CargoReturn_T::DoesNotExist, CargoVolume_T() };
	
}

Game_Economy::CargoReturn 
	Game_Economy::Objects::CombinationCargo::AddCargoItem(
		std::unique_ptr<Cargo> _new_cargo
	)
{
	if (!_new_cargo)
		return CargoReturn_T::InvalidCargo;
	Game_Economy::CargoReturn flags;
	if (contents.size() >= item_quantity_limit)
		flags += CargoReturn_T::ItemLimit;
	
	if (_new_cargo->GetMass().gross_kilogramms >
		GetMass().loaded_kilogramms)
		flags += CargoReturn_T::MassExceedded;

	if (_new_cargo->GetVolume().displacement_litres >
		GetVolume().remaining_litres)
		flags += CargoReturn_T::VolumeExceeded;

	if (!flags.Success())
		return flags;

	contents.emplace_back(std::move(_new_cargo));
	return Game_Economy::CargoReturn_T::Success;
}


Game_Economy::CargoReturn 
	Game_Economy::Objects::CombinationCargo::TakeCargoItem(
		std::unique_ptr<Game_Economy::Objects::Cargo> _cargo,
		const unsigned int _cargo_unique_id
	)
{
	for (auto it = contents.begin(); it != contents.end(); ++it) 
	{
		if ((*it)->GetUniqueID() == _cargo_unique_id) {
			_cargo = std::move(*it);
			contents.erase(it);
			return Game_Economy::CargoReturn_T::Success;
		}
	}
	return Game_Economy::CargoReturn_T::DoesNotExist;
}

void Game_Economy::Objects::CombinationCargo::TrashAllContents(const bool& _turn_off_saftey)
{
	if (!_turn_off_saftey)
		throw std::runtime_error(
			"CombinationCargo - Possible unintended trashing of cargo contents. Check Safety."
		);

	contents.clear();
}