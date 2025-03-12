#pragma once
#ifndef _CARGOTYPE_HPP_
#define _CARGOTYPE_HPP_

#include "TranspReq.hpp"

namespace Game_Economy
{
	class CargoType
	{
	public:
		CargoType()
			:
			cargo(static_cast<uint32_t>(CargoType_T::Clean)) {
		}
		CargoType(const CargoType_T& _cargo_type)
			:
			cargo(static_cast<uint32_t>(_cargo_type)) {
		}
	private:
		uint32_t cargo; // Member Variable
	private: // Private Member Functions
		float MaterialDensity() const;
		uint32_t FilterDensity() const;
		uint32_t FilterReq() const;
		std::string Print(const uint32_t& _print) const;
	public: // Setters
		void ChangeCargoType(CargoType_T _cargo_type);
		void CleanCargoType();
	public: // Getters
		CargoType_T GetCargoType() const;
		TranspReq GetTransportReq() const;
		float GetVolumeMultiplier() const;
	public: // Get Print Strings
		std::string PrintCargoName() const;
		std::string PrintDensity() const;
		std::string PrintAllDetails() const;
	public: // Conversions
		float Convert_kgToL(float _mass_kilogramms) const;
		float Convert_LTokg(float _volume_litres) const;
	public: // Boolean and Comparisons
		bool IsClean() const;
		bool IsPackaged() const;
		bool IsValidDensity() const;
		std::pair<bool, bool> WillFit(
			float _capacity_litres,
			float _gross_limit_kg) const;
		bool IsLowDensity() const;
	public: // Overloads
		bool operator == (const CargoType& _rhs) const
		{
			return (this->cargo == _rhs.cargo);
		}
		bool operator == (const CargoType_T& _rhs) const
		{
			return (this->cargo == static_cast<uint32_t>(_rhs));
		}
	};
}

#endif // !_CARGOTYPE_HPP_
