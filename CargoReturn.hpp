#pragma once
#ifndef _CARGORETURN_HPP_
#define _CARGORETURN_HPP_

#include <cstdint>
#include <string>

namespace Game_Economy
{
	enum class CargoReturn_T : uint16_t
		// Note - update TranslateCargoReturn_T() and 
		// TranslateExtCargoReturn_T
	{
		Success = 0x00u,

		CargoTypeMismatch = 0x0001u,
		MassExceedded = 0x0002u,
		VolumeExceeded = 0x0004u,
		InsufficientAvailable = 0x0008u,

		ItemLimit = 0x0010,
		ContainerHasContents = 0x0020u,
		NoAssignedCargo = 0x0040u,
		NotClean = 0x0080u,

		NotTransportable = 0x0100u,
		CargoClass = 0x0200,
		InvalidCargo = 0x0400,
		DoesNotExist = 0x0800,



		Unexpected = 0x8000
	};

	class CargoReturn
	{
	public:
		CargoReturn()
			:
			Flags(static_cast<CargoReturn_T>(0u)) {
		}
		CargoReturn(const CargoReturn_T& _flags)
			:
			Flags(_flags) {
		}
		CargoReturn(const CargoReturn& _other)
			:
			Flags(_other.Flags) {
		}
	private:
		CargoReturn_T Flags;
		CargoReturn_T Mask(uint16_t _mask) const;
	public:
		std::string Print() const;
		std::string PrintExt() const;
		bool Success() const  // returns true if all flags cleared (0u)
		{
			return (static_cast<uint16_t>(this->Flags) == 0u);
		}
		CargoReturn operator + (const CargoReturn_T& _rhs) const
		{
			return static_cast<CargoReturn_T>(static_cast<uint16_t>(_rhs) |
				static_cast<uint16_t>(this->Flags));
		}
		CargoReturn& operator += (const CargoReturn_T& _rhs)
		{
			return *this = *this + _rhs;
		}
		CargoReturn operator + (const CargoReturn& _rhs) const
		{
			return static_cast<CargoReturn_T>(static_cast<uint16_t>(_rhs.Flags) |
				static_cast<uint16_t>(this->Flags));
		}
		CargoReturn& operator += (const CargoReturn& _rhs)
		{
			return *this = *this + _rhs;
		}
		CargoReturn operator - (const CargoReturn_T _rhs) const
		{
			return static_cast<CargoReturn_T>(~static_cast<uint16_t>(_rhs) &
				static_cast<uint16_t>(this->Flags));
		}
		CargoReturn& operator -= (const CargoReturn_T& _rhs)
		{
			return *this = *this - _rhs;
		}
		bool operator == (const CargoReturn_T& _rhs) const
		{
			return
				((static_cast<uint16_t>(_rhs) &
					static_cast<uint16_t>(this->Flags)) !=0 );
		}
	};
}

#endif // ! _CARGORETURN_HPP_