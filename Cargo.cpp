#include "Cargo.hpp"
#include <sstream>

Game_Economy::Objects::Cargo::Cargo(
	unsigned int _cargo_unique_id,
	const Game_Economy::TranspReq& _transport_requirements,
	float _gross_limit_kilogramms, 
	float _displacement_litres,
	const std::string& _name
)
	:
	cargo_unique_id(_cargo_unique_id),
	transport_requirements(_transport_requirements),
	displacement_litres(_displacement_litres),
	gross_limit_kilogramms(_gross_limit_kilogramms),
	name(_name)
{
}

unsigned int Game_Economy::Objects::Cargo::GetUniqueID() const
{
	return cargo_unique_id;
}

Game_Economy::TranspReq Game_Economy::Objects::Cargo::GetTransportReq() const
{
	return transport_requirements.GetTransportReq();
}

std::string Game_Economy::Objects::Cargo::GetDetails() const
{
	std::ostringstream return_stream;
	return_stream << "(" << std::to_string(cargo_unique_id) << ") " << name << "\n"
		<< "Gross Weight: "
		<< Game_Math::Utilities::PrintFloat2(gross_limit_kilogramms) << "kg Displacement: "
		<< Game_Math::Utilities::PrintFloat2(displacement_litres) << "L\n";
	return return_stream.str();
}

std::string Game_Economy::Objects::Cargo::GetBriefDetails() const
{
	std::ostringstream return_stream;
	return_stream << "(" << std::to_string(GetUniqueID()) << ") " << name << " Weight: "
		<< Game_Math::Utilities::PrintFloat2(gross_limit_kilogramms) << "kg Displacement: "
		<< Game_Math::Utilities::PrintFloat2(displacement_litres) << "\n";
	return return_stream.str();
}

Game_Economy::CargoVolume_T Game_Economy::Objects::Cargo::GetVolume() const
{
	return { 0.0f, 0.0f, displacement_litres };
}

Game_Economy::CargoMass_T Game_Economy::Objects::Cargo::GetMass() const
{
	return { 0.0f, 0.0f, gross_limit_kilogramms };
}
