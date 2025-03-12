#pragma once
#ifndef _CARGO_HPP_
#define _CARGO_HPP_

#include "CargoType.hpp"
#include "CargoReturn.hpp"
#include <cstdint>
#include <utility>
#include <string>

namespace Game_Economy
{
	struct CargoMass_T
	{
		CargoMass_T()
			:
			loaded_kilogramms(0.0f),
			remaining_kilogramms(0.0f),
			gross_kilogramms(0.0f)
		{}
		CargoMass_T(float _load, float _remaining, float _gross)
			:
			loaded_kilogramms(_load),
			remaining_kilogramms(_remaining),
			gross_kilogramms(_gross)
		{}
		const float loaded_kilogramms;
		const float remaining_kilogramms;
		const float gross_kilogramms;
	};

	struct CargoVolume_T
	{
		CargoVolume_T()
			:
			loaded_litres(0.0f),
			remaining_litres(0.0f),
			displacement_litres(0.0f)
		{}
		CargoVolume_T(float _load, float _remaining, float _disp)
			:
			loaded_litres(_load),
			remaining_litres(_remaining),
			displacement_litres(_disp)
		{}
		const float loaded_litres;
		const float remaining_litres;
		const float displacement_litres;
	};

	enum class CargoClass_T
	{
		Cargo,
		BulkCargo,
		CombinationCargo
	};

	namespace Objects
	{
		class Cargo
		{
		public:
			Cargo(
				unsigned int _cargo_unique_id,
				const Game_Economy::TranspReq& _transport_requirements,
				float _gross_limit_kilogramms = 250.0f,
				float _displacement_litres = 500.0f,				
				const std::string& _name = "Unidentified Cargo Item"
			);
			Cargo(const Cargo&) = delete; // Prevents copying.
			Cargo(Cargo&&) = default;
			Cargo& operator = (Cargo&&) = default;
		public:
			unsigned int GetUniqueID() const;
			Game_Economy::TranspReq GetTransportReq() const;
			virtual std::string GetDetails() const;
			virtual std::string GetBriefDetails() const;
			virtual CargoVolume_T GetVolume() const;
			virtual CargoMass_T GetMass() const;
		private:
			const unsigned int cargo_unique_id;			
		protected:
			const Game_Economy::TranspReq transport_requirements;
			const float gross_limit_kilogramms;
			const float displacement_litres;
			const std::string name;
		};

		namespace CargoPresets
		{
		//	static Cargo BULKER_OF_CONCRETE_RUBBLE(unsigned int& _cargo_unique_id) {
		//		return Cargo{
		//		_cargo_unique_id,
		//		static_cast<float>(Game_Economy::CargoType_T::Cement) * 0.35,  // dry weight in kilograms
		//		575.0f, // volume of space container occupies in liters
		//		"Bag of Concrete Rubble."				
		//		};
		//	}
		//	static Cargo CHEMICAL_WASTE_DRUM(unsigned int& _cargo_unique_id) {
		//		return Cargo{
		//			_cargo_unique_id,
		//			static_cast<float>(Game_Economy::CargoType_T::H2S04) * 0.35,  // dry weight in kilograms
		//			200.0f,   // volume of space container occupies in cubic meters
		//			"44G Drum (Chemical Waste)DO NOT OPEN",
		//		};
		//	}
		//	static Cargo WOODEN_PALLET_STACK(unsigned int& _cargo_unique_id) {
		//		return Cargo{
		//			_cargo_unique_id,
		//			15.0f * 12.0f,  // dry weight in kilograms
		//			1200.0f,   // volume of space container occupies in cubic meters
		//			"Wooden Forklift Pallets (12)",
		//		};
		//	}
		//	static Cargo UNUSED_EMPTY_BARREL(const unsigned int& _cargo_unique_id)
		//	{
		//		return Cargo(
		//			_cargo_unique_id, 
		//			18.0f, 
		//			206.0f, 
		//			std::string("Discarded Barrel")
		//		);
		//	}
		//	static Cargo CONCRETE_BALLAST_BLOCK(const unsigned int _cargo_unique_id)
		//	{
		//		return Cargo(
		//			_cargo_unique_id, 
		//			static_cast<float>(Game_Economy::CargoType_T::Cement), 
		//			1000.0f, 
		//			std::string("Concrete Ballast Block")
		//		);
		//	}
		}		
	}
}

#endif // !_CARGO_HPP_
