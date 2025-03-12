#include "CargoType.hpp"
#include <sstream>

float Game_Economy::CargoType::MaterialDensity() const
{
	return static_cast<float>(FilterDensity());
}

uint32_t Game_Economy::CargoType::FilterDensity() const
{
	return cargo &
		static_cast<uint32_t>(Game_Economy::CargoType_T::CargoDensityMask);
}

uint32_t Game_Economy::CargoType::FilterReq() const
{
	return cargo &
		static_cast<uint32_t>(Game_Economy::CargoType_T::TranspReqMask);
}

std::string
Game_Economy::CargoType::Print(const uint32_t& _print) const
{
	auto print = static_cast<Game_Economy::CargoType_T>(_print);
	switch (print)
	{
	case Game_Economy::CargoType_T::Clean:
		return "This container is clean. No assigned cargo.";
		break;
	case Game_Economy::CargoType_T::Water:
		return "Non Potable Water";
		break;
	case Game_Economy::CargoType_T::WaterPotableBulk:
		return "Drinking Water(Bulk)";
		break;
	case Game_Economy::CargoType_T::WaterPotablePackaged:
		return "Drinking Water(Bottled)";
		break;
	case Game_Economy::CargoType_T::NH3:
		return "Anhydrous Ammonia(NH3)";
		break;
	case Game_Economy::CargoType_T::Cl2:
		return "Chlorine(Cl2)";
		break;
	case Game_Economy::CargoType_T::HF:
		return "Hydrogen Flouride(HFl)";
		break;
	case Game_Economy::CargoType_T::COCl2:
		return "Phosgene(COCl2)";
		break;
	case Game_Economy::CargoType_T::H2S04:
		return "Sulphuric Acid(H2SO4)";
		break;
	case Game_Economy::CargoType_T::HCl:
		return "Hydrocloric Acid(HCl)";
		break;
	case Game_Economy::CargoType_T::H2O2:
		return "Hydrogen Peroxide(H2O2)";
		break;
	case Game_Economy::CargoType_T::H3PO4:
		return "Phosphuric Acid(H3PO4)";
		break;
	case Game_Economy::CargoType_T::C2H6O2:
		return "Ethylene Glycol(C2H6O2) Hazardous";
		break;
	case Game_Economy::CargoType_T::C2H5OH:
		return "Ethanol(C2H5OH) Flammable";
		break;
	case Game_Economy::CargoType_T::C3H7OH:
		return "Propanol(C3H7OH) Flammable";
		break;
	case Game_Economy::CargoType_T::CH3OH:
		return "Methanol(CH30H) Flammable";
		break;
	case Game_Economy::CargoType_T::C4H9OH:
		return "Butanol(C8H9OH) Flammable";
		break;
	case Game_Economy::CargoType_T::C6H5OH:
		return "Phenol(C6H5OH) Flammable";
		break;
	case Game_Economy::CargoType_T::CH3C6H4OH:
		return "Cresol(CH3C6H4OH) Hazardous";
		break;
	case Game_Economy::CargoType_T::C8H9OH:
		return "Xylenol(C8H9OH) Flammable";
		break;
	case Game_Economy::CargoType_T::CaO:
		return "Calcium Oxide(CaO)";
		break;
	case Game_Economy::CargoType_T::KCl:
		return "Potassium Chloride(KCl)";
		break;
	case Game_Economy::CargoType_T::Na2CO3:
		return "Sodium Bicarbonate(Na2CO3)";
		break;
	case Game_Economy::CargoType_T::NaOH:
		return "Sodium Hydroxide(NaOH)";
		break;
	case Game_Economy::CargoType_T::NH4NO3:
		return "Ammonium Nitrate(NH4NO3)";
		break;
	case Game_Economy::CargoType_T::CaCO3:
		return "Calcium Carbonate(CaCO3)";
		break;
	case Game_Economy::CargoType_T::Ca_MgCO3_2:
		return "Dolomite(Ca(MgCO3)2) Rock";
		break;
	case Game_Economy::CargoType_T::CaSO4_2H2O:
		return "Gypsum(CaSO4(2H2O))";
		break;
	case Game_Economy::CargoType_T::FlyAsh:
		return "Fly Ash(Powder) Hazardous";
		break;
	case Game_Economy::CargoType_T::CementClinker:
		return "Prilled Clinker Cement";
		break;
	case Game_Economy::CargoType_T::Ca5_PO4_3F:
		return "Phosphate Rock(Ca5(PO4)3F)";
		break;
	case Game_Economy::CargoType_T::CO_NH2_2:
		return "Urea(CO(NH2)2) Granular";
		break;
	case Game_Economy::CargoType_T::C6H6:
		return "Benzene(C6H6) Hazardous";
		break;
	case Game_Economy::CargoType_T::NaC2H3O2Bulk:
		return "Sodium Acetate(NaC2H3O2)";
		break;
	case Game_Economy::CargoType_T::K2Cr2O7Bulk:
		return "Potassium Dichromate(K2(Cr2O7)) Bulk";
		break;
	case Game_Economy::CargoType_T::K2Cr2O7Packaged:
		return "Potassium Dichromate(K2(Cr2O7)) Packaged";
		break;
	case Game_Economy::CargoType_T::CaCl2:
		return "Calcium Chloride(CaCl2)";
		break;
	case Game_Economy::CargoType_T::AlCl3:
		return "Aluminium Chloride(AlCl3)";
		break;
	case Game_Economy::CargoType_T::TiO2:
		return "Titanium Dioxide(TiO2)";
		break;
	case Game_Economy::CargoType_T::LPG:
		return "Fuel (LPG)";
		break;
	case Game_Economy::CargoType_T::Petrol:
		return "Fuel (Petrol)";
		break;
	case Game_Economy::CargoType_T::Diesel:
		return "Fuel (Diesel)";
		break;
	case Game_Economy::CargoType_T::Aluminium:
		return "Aluminium";
		break;
	case Game_Economy::CargoType_T::AluminiumCoil:
		return "Steel Coil(s)(Aluminium)";
		break;
	case Game_Economy::CargoType_T::Copper:
		return "Copper";
		break;
	case Game_Economy::CargoType_T::Brass:
		return "Brass";
		break;
	case Game_Economy::CargoType_T::BrassCoil:
		return "Steel Coil(s)(Brass)";
		break;
	case Game_Economy::CargoType_T::Steel:
		return "Steel";
		break;
	case Game_Economy::CargoType_T::SteelCoil:
		return "Steel Coil(s)(Steel)";
		break;
	case Game_Economy::CargoType_T::StainlessSteel:
		return "Stainless Steel";
		break;
	case Game_Economy::CargoType_T::StainlessSteelCoil:
		return "Steel Coil(s)(Stainless Steel)";
		break;
	case Game_Economy::CargoType_T::Wheat:
		return "Grain (Wheat)";
		break;
	case Game_Economy::CargoType_T::Corn:
		return "Grain (Corn)";
		break;
	case Game_Economy::CargoType_T::Soy:
		return "Grain ( ())::::D )";
		break;
	case Game_Economy::CargoType_T::Barley:
		return "Grain (Barley)";
		break;
	case Game_Economy::CargoType_T::Oats:
		return "Grain (Oats)";
		break;
	case Game_Economy::CargoType_T::Sorghum:
		return "Grain (Sorghum)";
		break;
	case Game_Economy::CargoType_T::Rice:
		return "Grain (White Rice)";
		break;
	case Game_Economy::CargoType_T::SoftwoodsPackaged:
		return "Packaged Timber(Softwood)";
		break;
	case Game_Economy::CargoType_T::HardwoodsPackaged:
		return "Packaged Timber(Hardwood)";
		break;
	case Game_Economy::CargoType_T::SoftwoodsPlanks:
		return "Wooden Planks(Softwood)";
		break;
	case Game_Economy::CargoType_T::HardwoodsPlanks:
		return "Wooden Planks(Hardwood)";
		break;
	case Game_Economy::CargoType_T::SoftwoodsChips:
		return "Woodchips(Softwood)";
		break;
	case Game_Economy::CargoType_T::HardwoodsChips:
		return "Woodchips(Hardwood)";
		break;
	case Game_Economy::CargoType_T::PaperRoll:
		return "Paper Roll";
		break;
	case Game_Economy::CargoType_T::PaperCardRoll:
		return "Card Paper Roll";
		break;
	case Game_Economy::CargoType_T::PE:
		return "Granular Plastic(PE)";
		break;
	case Game_Economy::CargoType_T::HDPE:
		return "Granular Plastic(HDPE)";
		break;
	case Game_Economy::CargoType_T::PP:
		return "Granular Plastic(PP)";
		break;
	case Game_Economy::CargoType_T::PVC:
		return "Granular Plastic(PVC)";
		break;
	case Game_Economy::CargoType_T::ABS:
		return "Granular Plastic(ABS)";
		break;
	case Game_Economy::CargoType_T::Cement:
		return "Cement(Bulk)";
		break;
	case Game_Economy::CargoType_T::BaggedCement:
		return "Cement Bags";
		break;
	case Game_Economy::CargoType_T::Sand:
		return "Sand(Aggregate)";
		break;
	case Game_Economy::CargoType_T::Gravel:
		return "Gravel(Aggregate)";
		break;
	case Game_Economy::CargoType_T::SmallElectronics:
		return "Small Household Electronics";
		break;
	case Game_Economy::CargoType_T::MediumElectronics:
		return "Medium Domestic Electronics";
		break;
	case Game_Economy::CargoType_T::LargeElectronics:
		return "Large Commercial Electronics";
		break;
	case Game_Economy::CargoType_T::WhiteGoods:
		return "Domestic White Goods";
		break;
	case Game_Economy::CargoType_T::MachineComponentsL:
		return "Industrial Machinery Components";
		break;
	case Game_Economy::CargoType_T::MachineComponentsM:
		return "Spare Parts - Industrial Machines";
		break; 
	case Game_Economy::CargoType_T::CommercialMachinery:
		return "Commercial Machinery";
		break;		
	case Game_Economy::CargoType_T::HeavyComercialMachinery:
		return "Heavy Commercial Machinery";
		break;
	case Game_Economy::CargoType_T::IndustrialMachinery:
		return "Large Industrial Machinery";
		break;
	case Game_Economy::CargoType_T::SmallGoods:
		return "Deli Meats and Cheeses";
		break;
	case Game_Economy::CargoType_T::PackagedMeat:
		return "Packaged Meat Products";
		break;
	case Game_Economy::CargoType_T::CannedGoods:
		return "Canned Foods";
		break;
	case Game_Economy::CargoType_T::Cereals:
		return "Cerals and Dry Foods";
		break;
	case Game_Economy::CargoType_T::FreshFruit:
		return "Fresh Fruit";
		break;
	case Game_Economy::CargoType_T::SoftservePoop:
		return "Fresh Softserve Poop";
		break;
	case Game_Economy::CargoType_T::HardPoop:
		return "Fragrent Hard Poop";
		break;
	case Game_Economy::CargoType_T::LiquifiedPoop:
		return "Vitamin Poop Smoothie";
		break;
	case Game_Economy::CargoType_T::DriedPoop:
		return "Poop Jerky";
		break;
	}
	return "Error: CargoType_T-Unnamed type.";
}

Game_Economy::CargoType_T Game_Economy::CargoType::GetCargoType() const
{
	return static_cast<Game_Economy::CargoType_T>(cargo);
}

Game_Economy::TranspReq Game_Economy::CargoType::GetTransportReq() const
{
	return static_cast<Game_Economy::TranspReq_T>(FilterReq());
}

float Game_Economy::CargoType::GetVolumeMultiplier() const
{
	auto flags = FilterReq();
	for (uint32_t i = static_cast<uint32_t>(
		Game_Economy::CargoType_T::PackagedSmall5); i != 0u;
		i = i << 1)
	{
		switch (static_cast<Game_Economy::CargoType_T>(flags & i))
		{
		case Game_Economy::CargoType_T::PackagedSmall5:
			return static_cast<float>(Game_Economy::CargoType_T::PackagedS);
		case Game_Economy::CargoType_T::PackagedMedium125:
			return static_cast<float>(Game_Economy::CargoType_T::PackagedM);
		case Game_Economy::CargoType_T::PackagedLarge1000:
			return static_cast<float>(Game_Economy::CargoType_T::PackagedL);
		case Game_Economy::CargoType_T::PackagedExtraLarge4000:
			return static_cast<float>(Game_Economy::CargoType_T::PackagedXL);
		}
	}
	return static_cast<float>(Game_Economy::CargoType_T::Volume);
}

std::string Game_Economy::CargoType::PrintCargoName() const
{
	return Print(cargo);
}

std::string Game_Economy::CargoType::PrintDensity() const
{
	auto density = Convert_LTokg(GetVolumeMultiplier());
	std::ostringstream stream;
	stream << Game_Math::Utilities::PrintFloat3(density);
	if (IsPackaged())
		stream << "(kg)";
	else
		stream << "kg/L";
	return stream.str();
}

std::string Game_Economy::CargoType::PrintAllDetails() const
{
	std::ostringstream stream;
	stream << "Type of Cargo:\t";
	if (IsPackaged())
		stream << "Packaged - "
		<< Game_Math::Utilities::PrintFloat0(GetVolumeMultiplier()) << "L, "
		<< PrintDensity();
	else
		stream << "\tBy volume ("
		<< PrintDensity() << ")";

	stream << "\n\n\t" << PrintCargoName() << "\n\n";
	TranspReq transpreq = { GetTransportReq() };
	stream << ".\nThe transport of this product "
		<< "requires \na container that is:\n\n";
	stream << transpreq.PrintTransportReq();
	return stream.str();
}

bool Game_Economy::CargoType::IsClean() const
{
	return cargo == static_cast<uint32_t>(CargoType_T::Clean);
}

bool Game_Economy::CargoType::IsPackaged() const
{
	//auto r = static_cast<uint32_t>(CargoType_T::PackagedExtraLarge4000);
	return (static_cast<uint32_t>(CargoType_T::IsPackaged) & cargo);
}

bool Game_Economy::CargoType::IsValidDensity() const
{	
	auto mask = static_cast<uint32_t>(CargoType_T::CargoDensityMask);
	return ((cargo & mask) != 0);		
}

std::pair<bool, bool> 
	Game_Economy::CargoType::WillFit(
		float _capacity_litres,
		float _gross_limit_kg) const
{
	auto volume_per_unit = GetVolumeMultiplier();
	auto mass_per_unit = Convert_LTokg(volume_per_unit);
	return {
		(volume_per_unit < _capacity_litres),
		(mass_per_unit < _gross_limit_kg)
	};	
}

bool Game_Economy::CargoType::IsLowDensity() const
{
	return (MaterialDensity() < 1000.0f);
}

float Game_Economy::CargoType::Convert_kgToL(float _mass_kilogramms) const
{
	return (_mass_kilogramms / static_cast<float>(FilterDensity())
		* Game_Math::Constants::fLITRESPERCUBICMETER);
}

float Game_Economy::CargoType::Convert_LTokg(float _volume_litres) const
{
	return _volume_litres * static_cast<float>(FilterDensity())
		* Game_Math::Constants::fKILORGAMMSPERGRAMM;
}

void Game_Economy::CargoType::ChangeCargoType(Game_Economy::CargoType_T _cargo_type)
{
	cargo = static_cast<uint32_t>(_cargo_type);
}

void Game_Economy::CargoType::CleanCargoType()
{
	cargo = static_cast<uint32_t>(Game_Economy::CargoType_T::Clean);
}