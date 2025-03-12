#pragma once
#ifndef _BULKCARGO_HPP_
#define _BULKCARGO_HPP_

#include "Cargo.hpp"
#include <limits>
#include <stdexcept>

namespace Game_Economy
{
	namespace Objects
	{
		class BulkCargo : public Game_Economy::Objects::Cargo
		{
		public:
			BulkCargo(
				unsigned int _cargo_unique_id,
				const Game_Economy::TranspReq& _transport_requirements,
				const Game_Economy::TranspReq& _attributes,
				float _gross_limit_kilogramms = 500.0f,
				float _displacement_litres = 1000.0f,
				const std::string& _name = "Unidentified Bulk Cargo Item",
				float _tare_kilogramms = 25.0f,
				float _capacity_litres = 800.0f
			);
			BulkCargo(BulkCargo&&) = default;
			BulkCargo& operator = (BulkCargo&&) = default;
		private:
			CargoReturn CompareAvailableCapacity(
				float _volume_litres_added,
				float _mass_kilogramms_added
			);
			float GetPercentageLoaded_Mass() const;
			float GetPercentageLoaded_Volume() const;
			float GetGrossWeight() const;
		public:
			Game_Economy::TranspReq GetAttributes() const;
			std::string GetDetails() const override;
			std::string GetBriefDetails() const override;
			Game_Economy::CargoType GetCargoType() const;
			Game_Economy::CargoMass_T GetMass() const override;
			Game_Economy::CargoVolume_T GetVolume() const override;
			Game_Economy::CargoReturn Add(float _volume_units_litres = 1.0f);
			Game_Economy::CargoReturn Take(float _volume_units_litres = 1.0f);
			Game_Economy::CargoReturn CleanBulkCargo(bool _force = false);
			Game_Economy::CargoReturn AssignCargoType(
				const CargoType& _cargo_type, bool _force = false);
		private:
			const Game_Economy::TranspReq attributes;
			Game_Economy::CargoType cargo_type;
			float tare_kilogramms;
			float mass_loaded_kilogramms;
			float volume_loaded_litres;
			float capacity_litres;
		};

		namespace BulkCargoPresets
		{			
			//// PALLET BOXED
			static BulkCargo WOODEN_FORKLIFT_PALLET(unsigned int _cargo_unique_id) {
				return BulkCargo{
					_cargo_unique_id,
					{ Game_Economy::TranspReq_T::IBC },
					{Game_Economy::TranspReq_T::PackagedLarge1000 ,
					Game_Economy::TranspReq_T::PackagedMedium125,
					Game_Economy::TranspReq_T::PackagedSmall5,
					Game_Economy::TranspReq_T::Hazardous ,
					Game_Economy::TranspReq_T::WoodProduct,
					Game_Economy::TranspReq_T::Pallet
					},
					1000.0f, // mass capacity limit in kilograms
					1200.0f,   // volume of space container occupies in cubic meters
					"Wooden Forklift Pallet",
					15.0f,  // dry weight in kilograms
					1050.0f     // volume limit in liters (not applicable for pallets)
				};
			}
			static BulkCargo PLASTIC_PALLET(unsigned int _cargo_unique_id) {
				return BulkCargo{
					_cargo_unique_id,
					{ Game_Economy::TranspReq_T::IBC },
					{Game_Economy::TranspReq_T::PackagedLarge1000 ,
					Game_Economy::TranspReq_T::PackagedMedium125,
					Game_Economy::TranspReq_T::PackagedSmall5,
					Game_Economy::TranspReq_T::Hazardous ,
					Game_Economy::TranspReq_T::WoodProduct,
					Game_Economy::TranspReq_T::Pallet				
					},
					800.0f, // mass capacity limit in kilograms
					1200.0f,   // volume of space container occupies in cubic meters
					"Plastic Forklift Pallet",
					10.0f,  // dry weight in kilograms
					1050.0f     // volume limit in liters
				};
			}
			//// LIQUID METAL
			//static BulkCargo OIL_DRUM44GAL(unsigned int& _cargo_unique_id) {
			//	return BulkCargo{
			//		_cargo_unique_id,
			//		12.0f,  // dry weight in kilograms
			//		200.0f,   // volume of space container occupies in cubic meters
			//		"44 Gallon Oil Drum",
			//		200.0f, // mass capacity limit in kilograms
			//		166.5f  // volume limit in liters (44 gallons)
			//	};
			//}
			//// LIQUID POLY
			//static BulkCargo IBC30LPOLYBARREL(const unsigned int& _cargo_unique_id)
			//{
			//	return BulkCargo{
			//		_cargo_unique_id,
			//		15.0f,
			//		120.0f,
			//		std::string("114L Plastic Barrel"),
			//		170.0f,
			//		114.0f
			//	};
			//}
			static BulkCargo IBC55LPOLYBARREL(unsigned int _cargo_unique_id)
			{
				return BulkCargo{
					_cargo_unique_id,
					{ Game_Economy::TranspReq_T::IBC },
					{Game_Economy::TranspReq_T::Liquid ,
					Game_Economy::TranspReq_T::Hazardous ,
					Game_Economy::TranspReq_T::Sealed,
					Game_Economy::TranspReq_T::Powder,
					Game_Economy::TranspReq_T::Granular,
					},
					270.0f,
					210.0f,
					std::string("208L Plastic Barrel"),
					25.0f,
					208.0f
				};
			}
			//static BulkCargo IBC1000LTOTE(const unsigned int& _cargo_unique_id) {
			//	return BulkCargo{
			//		_cargo_unique_id,
			//		100.0f,
			//		1300.0f, "1000L IBC Tote",
			//		1200.0f,
			//		1000.0f 
			//	};
			//}
			//// BULK BAG
			static BulkCargo IBC_BULK_BAG_FULL(unsigned int _cargo_unique_id) {
				return BulkCargo{
				_cargo_unique_id,
				{ Game_Economy::TranspReq_T::IBC },
				{Game_Economy::TranspReq_T::Aggregate ,
				Game_Economy::TranspReq_T::Granular ,
				Game_Economy::TranspReq_T::IBC
				},
				1500.0f, // mass capacity limit in kilograms
				1050.0f, // volume of space container occupies in liters
				"IBC Bulk Bag (1000kg)",
				60.0f,  // dry weight in kilograms
				1000.0f  // volume limit in liters (approximate)
				};
			}
			static BulkCargo IBC_BULK_BAG_HALF(unsigned int _cargo_unique_id) {
				return BulkCargo{
				_cargo_unique_id,
				{ Game_Economy::TranspReq_T::IBC },
				{Game_Economy::TranspReq_T::Aggregate ,
				Game_Economy::TranspReq_T::Granular ,
				Game_Economy::TranspReq_T::IBC
				},
				750.0f, // gross limit kg
				575.0f, // displacement L
				"IBC Bulk Bag (500kg)",
				30.0f,  // tare / dry kg
				500.0f   // Capacity L
				};
			}
			//// RIGID RIBC
			static BulkCargo RIBC_250L(unsigned int _cargo_unique_id) {
				return BulkCargo{
				_cargo_unique_id,
				{ Game_Economy::TranspReq_T::IBC },
					{Game_Economy::TranspReq_T::Granular ,
				Game_Economy::TranspReq_T::IBC,
				Game_Economy::TranspReq_T::Hazardous,
				Game_Economy::TranspReq_T::Covered
				},
				400.0f, // mass capacity limit in kilograms
				300.0f, // volume of space container occupies in liters
				"RIBC Rigid Bulk Container (250L)",
				40.0f,  // dry weight in kilograms
				250.0f  // volume limit in liters
				};
			}
			//static BulkCargo RIBC_500L(unsigned int& _cargo_unique_id) {
			//	return BulkCargo{
			//	_cargo_unique_id,
			//	80.0f,  // dry weight in kilograms
			//	640.0f, // volume of space container occupies in liters
			//	"RIBC Rigid Bulk Container (500L)",
			//	800.0f, // mass capacity limit in kilograms
			//	500.0f  // volume limit in liters
			//	};
			//}
			//static BulkCargo RIBC_1000L(unsigned int& _cargo_unique_id) {
			//	return BulkCargo{
			//	_cargo_unique_id,
			//	120.0f,  // dry weight in kilograms
			//	1000.0f, // volume of space container occupies in liters
			//	"RIBC Rigid Bulk Container (1000L)",
			//	1200.0f, // mass capacity limit in kilograms
			//	1000.0f  // volume limit in liters
			//	};
			//}
			//static BulkCargo RIBC_1500L(unsigned int& _cargo_unique_id) {
			//	return BulkCargo{
			//	_cargo_unique_id,
			//	180.0f,  // dry weight in kilograms
			//	1500.0f, // volume of space container occupies in liters
			//	"RIBC Rigid Bulk Container (1500L)",
			//	1800.0f, // mass capacity limit in kilograms
			//	1500.0f  // volume limit in liters
			//	};
			//}
			//// HOPPER
			//static BulkCargo HOPPER_IBC_1000L(unsigned int& _cargo_unique_id) {
			//	return BulkCargo{
			//	_cargo_unique_id,
			//	150.0f,  // dry weight in kilograms
			//	1800.0f, // volume of space container occupies in liters
			//	"Hopper IBC 1000L",
			//	1200.0f, // mass capacity limit in kilograms
			//	1000.0f  // volume limit in liters
			//	};
			//}
			//static BulkCargo HOPPER_IBC_1500L(unsigned int& _cargo_unique_id) {
			//	return BulkCargo{
			//	_cargo_unique_id,
			//	220.0f,  // dry weight in kilograms
			//	2100.0f, // volume of space container occupies in liters
			//	"Hopper IBC 1500L",
			//	1800.0f, // mass capacity limit in kilograms
			//	1500.0f  // volume limit in liters
			//	};
			//}
		}
	}
}

#endif // !_BULKCARGO_HPP_