#include "BulkCargo.hpp"
#include <sstream>

Game_Economy::Objects::BulkCargo::BulkCargo(
	unsigned int _cargo_unique_id,
	const Game_Economy::TranspReq& _transport_requirements,
	const Game_Economy::TranspReq& _attributes,
	float _gross_limit_kilogramms,
	float _displacement_litres,
	const std::string& _name,
	float _tare_kilogramms,
	float _capacity_litres
)
	:
	Game_Economy::Objects::Cargo{ 
		_cargo_unique_id, 
		_transport_requirements,
		_gross_limit_kilogramms, 
		_displacement_litres, 
		_name },
		attributes(_attributes),
	mass_loaded_kilogramms(0.0f), 
	volume_loaded_litres(0.0f),
	tare_kilogramms(_tare_kilogramms),
	capacity_litres(_capacity_litres)
{
}

Game_Economy::CargoReturn 
	Game_Economy::Objects::BulkCargo::CompareAvailableCapacity(
		float _proposed_volume_litres, 
		float _resulting_mass_kilogramms
	)
{	
	CargoReturn cargo_return;
	if (_proposed_volume_litres > capacity_litres)
		cargo_return += Game_Economy::CargoReturn_T::VolumeExceeded;
		
	if ((_resulting_mass_kilogramms + tare_kilogramms) > gross_limit_kilogramms)
		cargo_return += Game_Economy::CargoReturn_T::MassExceedded;

	return cargo_return;
}

float Game_Economy::Objects::BulkCargo::GetPercentageLoaded_Mass() const
{
	return Game_Math::Utilities::GetPercentage(
		mass_loaded_kilogramms, gross_limit_kilogramms);
}

float Game_Economy::Objects::BulkCargo::GetPercentageLoaded_Volume() const
{
	return Game_Math::Utilities::GetPercentage(
		volume_loaded_litres, capacity_litres);
}

float Game_Economy::Objects::BulkCargo::GetGrossWeight() const
{
	return tare_kilogramms + mass_loaded_kilogramms;
}

Game_Economy::TranspReq Game_Economy::Objects::BulkCargo::GetAttributes() const
{
	return attributes.GetTransportReq();
}

std::string Game_Economy::Objects::BulkCargo::GetDetails() const
{
	std::ostringstream return_stream;
	return_stream << "(" << std::to_string(GetUniqueID()) << ") " << name
		<< "\tDisplacement: "
		<< static_cast<unsigned int>(std::round(displacement_litres)) << "L\n"
		<< "Tare: " << Game_Math::Utilities::PrintFloat2(tare_kilogramms)
		<< "kg Gross: "
		<< Game_Math::Utilities::PrintFloat2(GetGrossWeight()) << "kg Max:"
		<< Game_Math::Utilities::PrintFloat0(gross_limit_kilogramms) << "kg\n"
		<< "Contents:\tVolume: "
		<< Game_Math::Utilities::PrintFloat2(volume_loaded_litres)
		<< "/" << Game_Math::Utilities::PrintFloat2(capacity_litres)
		<< "L (" << Game_Math::Utilities::PrintFloat2(GetPercentageLoaded_Volume())
		<< "%)\n\t" << cargo_type.PrintCargoName();
	
	return return_stream.str();
}

std::string Game_Economy::Objects::BulkCargo::GetBriefDetails() const
{
	std::ostringstream return_stream;
	return_stream << "(" << std::to_string(GetUniqueID()) << ") " << name 
		<< "(" << cargo_type.PrintCargoName() << ") Weight: "
		<< Game_Math::Utilities::PrintFloat2(GetGrossWeight()) << "kg Displacement: "
		<< Game_Math::Utilities::PrintFloat2(displacement_litres) << "L\n";
	return return_stream.str();
}

Game_Economy::CargoType Game_Economy::Objects::BulkCargo::GetCargoType() const
{
	return cargo_type;
}

Game_Economy::CargoMass_T Game_Economy::Objects::BulkCargo::GetMass() const
{
	return { 
		mass_loaded_kilogramms,
		gross_limit_kilogramms - mass_loaded_kilogramms - tare_kilogramms,
		mass_loaded_kilogramms + tare_kilogramms
	};
}

Game_Economy::CargoVolume_T Game_Economy::Objects::BulkCargo::GetVolume() const
{
	if (cargo_type.Convert_kgToL(gross_limit_kilogramms - tare_kilogramms)
		> capacity_litres)
	{
		return {
			volume_loaded_litres,
			capacity_litres - volume_loaded_litres,
			displacement_litres
		};
	}
	else
	{
		return {
			volume_loaded_litres,
			cargo_type.Convert_kgToL(gross_limit_kilogramms - tare_kilogramms)
			- volume_loaded_litres,
			displacement_litres
		};
	}
}

Game_Economy::CargoReturn 
	Game_Economy::Objects::BulkCargo::Add(
		float _volume_units_litres)
{
	if (cargo_type.IsClean())
		// Can't fill if not assigned a cargo type.
		return Game_Economy::CargoReturn_T::NoAssignedCargo;		
	
	float multiplier = cargo_type.GetVolumeMultiplier();
	float new_volume =  (_volume_units_litres * multiplier) + volume_loaded_litres;
	float new_mass = cargo_type.Convert_LTokg(new_volume) + tare_kilogramms;
	// Check propsed volume and mass against limits specified.
	Game_Economy::CargoReturn flags = CompareAvailableCapacity(new_volume, new_mass);
	
	if (flags.Success())
	{
		// Proposed new volume is below limits.
		volume_loaded_litres = new_volume;
		mass_loaded_kilogramms = new_mass - tare_kilogramms;
	}
	return flags;
}

Game_Economy::CargoReturn
	Game_Economy::Objects::BulkCargo::Take(float _volume_units_litres)
{
	if (cargo_type.IsClean())
		return Game_Economy::CargoReturn_T::NoAssignedCargo;

	float multiplier = cargo_type.GetVolumeMultiplier();
	float new_volume = volume_loaded_litres - 
		(_volume_units_litres * multiplier);

	if (new_volume < 0.0f)
		return Game_Economy::CargoReturn_T::InsufficientAvailable;

	volume_loaded_litres = new_volume;
	mass_loaded_kilogramms = cargo_type.Convert_LTokg(volume_loaded_litres);
	return Game_Economy::CargoReturn_T::Success;
}

Game_Economy::CargoReturn 
	Game_Economy::Objects::BulkCargo::CleanBulkCargo(bool _force)
{
	if (!_force)
	{
		if (GetPercentageLoaded_Volume() > 0.025f)

			return Game_Economy::CargoReturn_T::ContainerHasContents;
	}
	
	volume_loaded_litres = 0.0f;
	mass_loaded_kilogramms = 0.0f;
	cargo_type.ChangeCargoType(Game_Economy::CargoType_T::Clean);
	return Game_Economy::CargoReturn_T::Success;
}

Game_Economy::CargoReturn 
	Game_Economy::Objects::BulkCargo::AssignCargoType(
		const Game_Economy::CargoType& _cargo_type,
		bool _force)
{
	Game_Economy::CargoReturn cargo_return;
	if (!_force)
	{
		if (!cargo_type.IsClean())
			cargo_return += Game_Economy::CargoReturn_T::NotClean;		
	}
	else
		// If _force ==  true 
		// the object is being cleaned (contents trashed).
	{
		CleanBulkCargo(_force);
	}
	// Irrespective of _force, compatibilit checks are performed.
	if (!_cargo_type.IsValidDensity())
		cargo_return += Game_Economy::CargoReturn_T::InvalidCargo;
	
	auto _cap_mass = _cargo_type.WillFit(
		capacity_litres,gross_limit_kilogramms);
	if (!_cap_mass.first)
		cargo_return += CargoReturn_T::VolumeExceeded;
	if (!_cap_mass.second)
		cargo_return += CargoReturn_T::MassExceedded;

	if (!attributes.IsCompatible(_cargo_type.GetCargoType()))
	{
		cargo_return += Game_Economy::CargoReturn_T::CargoClass;
	}
	if (cargo_return.Success())
	{
		cargo_type.ChangeCargoType(_cargo_type.GetCargoType());
	}
	return cargo_return;
}