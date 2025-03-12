#include "TranspReq.hpp"
#include <sstream>

Game_Economy::TranspReq::TranspReq(
	const std::initializer_list<Game_Economy::TranspReq_T> _requirements)
{
	uint32_t req_in = 0u;
	for(const auto & req: _requirements)	
		req_in |= static_cast<uint32_t>(req);
	requirements = req_in;
}

uint32_t Game_Economy::TranspReq::TheseReq() const
{
	return requirements &
		static_cast<uint32_t>(Game_Economy::TranspReq_T::MaskFlags);
}

uint32_t Game_Economy::TranspReq::ThoseReq(const uint32_t _candidate) const
{
	return _candidate & 
		static_cast<uint32_t>(Game_Economy::TranspReq_T::MaskFlags);
}

std::string Game_Economy::TranspReq::Print(const uint32_t _print) const
{
	auto print = static_cast<Game_Economy::TranspReq_T>(_print);
	switch (print)
	{
	case Game_Economy::TranspReq_T::NotTransportable:
		return "Fixed. Not transportable.";
		break;
	case Game_Economy::TranspReq_T::Sealed:
		return "Sealed to prohibit leaks or contamination.";
		break;
	case Game_Economy::TranspReq_T::Rail:
		return "A suitable rail car.";
		break;
	case Game_Economy::TranspReq_T::IBC:
		return "An appropriately selected IBC.";
		break;
	case Game_Economy::TranspReq_T::Pallet:
		return "A fork lift pallet.";
		break;
	case Game_Economy::TranspReq_T::Covered:
		return "Equipped with a cover to protect contents.";
		break;
	case Game_Economy::TranspReq_T::LiningOrFoodsafe:
		return "A suitably lined container.";
		break;
	case Game_Economy::TranspReq_T::Hazardous:
		return "Appropriate for hazardous materials.";
		break;
	case Game_Economy::TranspReq_T::CompressedGas:
		return "Designed to transport compressed or liquified gasses.";
		break;
	case Game_Economy::TranspReq_T::Liquid:
		return "A bulk liquids container.";
		break;
	case Game_Economy::TranspReq_T::Granular:
		return "Suitable for granular bulk materials.";
		break;
	case Game_Economy::TranspReq_T::Powder:
		return "Configured for powdered bulk materials.";
		break;
	case Game_Economy::TranspReq_T::Aggregate:
		return "Suitable for transporting aggregates.";
		break;
	case Game_Economy::TranspReq_T::WoodProduct:
		return "Made to transport wood and pulp products.";
		break;
	case Game_Economy::TranspReq_T::PackagedSmall5:
		return "Appropriate for small cartons up to 5L.";
		break;
	case Game_Economy::TranspReq_T::PackagedMedium125:
		return "Apropriate for medium cartons up to 125L.";
		break;
	case Game_Economy::TranspReq_T::PackagedLarge1000:
		return "Apropriate for large packaged items up to 1000L.";
		break;
	case Game_Economy::TranspReq_T::PackagedExtraLarge4000:
		return "Apropriate for large items up to 4000L.";
		break;
	}
	return "";
}

Game_Economy::TranspReq_T Game_Economy::TranspReq::GetTransportReq() const
{
	return static_cast<Game_Economy::TranspReq_T>(requirements);
}

std::string Game_Economy::TranspReq::PrintTransportReq() const
{
	uint32_t i = Game_Economy::Constants::transport_req_lsb;
	uint32_t req = TheseReq();
	std::ostringstream stream;
	std::string str;
	for (; i != 0u; i = i << 1)
	{
		str = Print(i & req);
		if (!str.empty())
			stream << "-" << str << "\n";
	}
	return stream.str();
}

bool Game_Economy::TranspReq::IsCompatible(const CargoType_T& _candidate_cargo) const
{
	auto candidate = ThoseReq(static_cast<uint32_t>(_candidate_cargo));
	auto resolve = TheseReq() & candidate;
	bool agree = resolve == candidate;
	return agree;
}

bool Game_Economy::TranspReq::IsCompatible(const TranspReq_T& _candidate_container) const
{
	auto candidate = static_cast<uint32_t>(_candidate_container);
	return ((TheseReq() & candidate) == candidate);
}