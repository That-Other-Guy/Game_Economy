#pragma once
#ifndef _COMBINATIONCARGO_HPP_
#define _COMBINATIONCARGO_HPP_

#include "BulkCargo.hpp"
#include <vector>
#include <memory>

namespace Game_Economy
{	
	struct CargoItemsCount_T
	{
		CargoItemsCount_T(
			const unsigned int _qty_loaded,
			const unsigned int _qty_available
		) :
			items_loaded_count(_qty_loaded),
			items_available_count(_qty_available)
		{}
		const unsigned int items_loaded_count;
		const unsigned int items_available_count;
	};

	namespace Objects
	{
		class CombinationCargo : public Game_Economy::Objects::Cargo
		{
		public:
			CombinationCargo(
				const unsigned int& _cargo_unique_id,
				Game_Economy::TranspReq_T _transport_requirements,
				const float& _displacement_litres = 5000.0f,
				const float& _dry_weight_kilogramms = 1000.0f,
				const std::string _name = "Unnamed Cargo Assortment",
				const unsigned int& _item_quantity_limit = 0,
				const float& _mass_limit_kilogramms = 0.0f,
				const float& _volume_limit_litres = 0.0f
			);
			CombinationCargo(CombinationCargo&&) = default;
			CombinationCargo& operator = (CombinationCargo&&) = default;
		private:
			float GetLoadedMass() const;
			float GetGrossWeight() const;
			float GetLoadedVolume() const; 
			float GetPercentageLoaded_Mass() const;
			float GetPercentageLoaded_Volume() const;
		public:
			std::string GetDetails(const std::string& _deliminator = "\n") const;
			std::string GetBriefDetails() const override;			
			Game_Economy::CargoMass_T GetMass() const override;			
			Game_Economy::CargoVolume_T GetVolume() const override;
			Game_Economy::CargoItemsCount_T GetItemsCount() const;
			Game_Economy::CargoReturn 
				CheckForCargoItem(const unsigned int _cargo_unique_id) const;
			std::pair < Game_Economy::CargoReturn, CargoMass_T>
				CheckCargoItemMass(const unsigned int _cargo_unique_id);
			std::pair < Game_Economy::CargoReturn, CargoVolume_T>
				CheckCargoItemVolume(const unsigned int _cargo_unique_id);
			Game_Economy::CargoReturn AddCargoItem(std::unique_ptr<Cargo> _new_cargo);
			Game_Economy::CargoReturn TakeCargoItem(std::unique_ptr<Cargo> _cargo, const unsigned int _cargo_unique_id);
			void TrashAllContents(const bool& _turn_off_saftey = false); // Unconditional.
		private:
			unsigned int item_quantity_limit;
			std::vector<std::unique_ptr<Cargo>> contents;
			float mass_limit_kilogramms;
			float volume_limit_litres;						
		};
		namespace CombinationCargoPresets
		{

		}
	}
}

#endif // !_COMBINATIONCARGO_HPP_



