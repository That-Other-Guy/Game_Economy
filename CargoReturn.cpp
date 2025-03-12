#include "CargoReturn.hpp"
#include <sstream>

Game_Economy::CargoReturn_T Game_Economy::CargoReturn::Mask(uint16_t _mask) const
{
	return static_cast<CargoReturn_T>(static_cast<uint16_t>(Flags) & _mask);
}

std::string Game_Economy::CargoReturn::Print() const
{
	if (Success())
		return "Success!\n";
	std::ostringstream stream;
	uint16_t mask = 1u;
	std::ostringstream return_stream;
	for (; mask != 0u; mask = mask << 1)
	{
		switch (Mask(mask))
		{
		case Game_Economy::CargoReturn_T::CargoTypeMismatch:
			stream << "Wrong cargo!\n";
			break;
		case Game_Economy::CargoReturn_T::MassExceedded:
			stream << "Too heavy!\n";
			break;
		case Game_Economy::CargoReturn_T::VolumeExceeded:
			stream << "Too much!\n";
			break;
		case Game_Economy::CargoReturn_T::InsufficientAvailable:
			stream << "Not enough.\n";
			break;
		case Game_Economy::CargoReturn_T::ItemLimit:
			stream << "Item limit reached.\n";
			break;
		case Game_Economy::CargoReturn_T::ContainerHasContents:
			stream << "Not empty!\n";
			break;
		case Game_Economy::CargoReturn_T::NoAssignedCargo:
			stream << "No assigned cargo type.\n";
			break;
		case Game_Economy::CargoReturn_T::NotClean:
			stream << "Not cleaned.\n";
			break;
		case Game_Economy::CargoReturn_T::NotTransportable:
			stream << "Not transportable.\n";
			break;
		case Game_Economy::CargoReturn_T::CargoClass:
			stream << "Cargo class refused.\n";
			break;
		case Game_Economy::CargoReturn_T::InvalidCargo:
			stream << "Invalid or missing cargo.\n";
			break;
		case Game_Economy::CargoReturn_T::DoesNotExist:
			stream << "Item not here.\n";
			break;
		case Game_Economy::CargoReturn_T::Unexpected:
			stream << "Unexpected.\n";
			break;
		}
	}
	return stream.str();
}

std::string Game_Economy::CargoReturn::PrintExt() const
{
	if (Success())
		return "The cargo has been successfully handled.\n";

	uint16_t mask = 1u;
	std::ostringstream return_stream;
	for (; mask != 0u; mask = mask << 1)
	{
		switch (Mask(mask))
		{
		case Game_Economy::CargoReturn_T::CargoTypeMismatch:
			return_stream << "This location cannot accept this type of cargo. \n"
				<< "Either the it can't carry this type of cargo or\n"
				<< " it is already partially filled by a different cargo type.\n";			
			break;
		case Game_Economy::CargoReturn_T::MassExceedded:
			return_stream << "This destination cannont accept the requested quantity.\n"
				<< "It will be exceed it's weight limit.\n";
			break;
		case Game_Economy::CargoReturn_T::VolumeExceeded:
			return_stream << "This destination cannont accept the requested quantity.\n"
				<< "It does not have the required space.\n";
			break;
		case Game_Economy::CargoReturn_T::InsufficientAvailable:
			return_stream << "The destination does not have the requested quantity.\n";
			break;
		case Game_Economy::CargoReturn_T::ItemLimit:
			return_stream << "It is not possible to place any more cargo items in this location.\n";
			break;
		case Game_Economy::CargoReturn_T::ContainerHasContents:
			return_stream << "This location still has a quantity of cargo.\n";
			break;
		case Game_Economy::CargoReturn_T::NoAssignedCargo:
			return_stream << "No cargo type has been assigned to this container.\n";
			break;		
		case Game_Economy::CargoReturn_T::NotClean:
			return_stream << "This location still has residual cargo that\n"
				<< "should be cleaned out.\n";
			break;
		case Game_Economy::CargoReturn_T::NotTransportable:
			return_stream << "This storage conatiner is fixed and not able to be transported\n";
		case Game_Economy::CargoReturn_T::CargoClass:
			return_stream << "The cargo class has been refused by destination.\n";
			break;
		case Game_Economy::CargoReturn_T::InvalidCargo:
			return_stream << "The cargo item you are attempting to move does not exist.\n";
			break;
		case Game_Economy::CargoReturn_T::DoesNotExist:
			return_stream << "The requested cargo is not in this location.\n";
			break;
		case Game_Economy::CargoReturn_T::Unexpected:
			return_stream << "Unexpected scenario encountered.\n";
			break;

		}
	}
	return "Error - CargoReturn.PrintExt()?\n";
}