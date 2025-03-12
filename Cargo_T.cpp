#include "Cargo_T.hpp"

Game_Economy::CargoType_T Game_Economy::SpawnCargo(
	const Game_Economy::CargoTypeSpawn_T& _type)
{
	switch (_type)
	{
	case Game_Economy::CargoTypeSpawn_T::Water:
		return Game_Economy::CargoType_T::Water;
		break;
	case Game_Economy::CargoTypeSpawn_T::WaterPotableBulk:
		return Game_Economy::CargoType_T::WaterPotableBulk;
		break;
	case Game_Economy::CargoTypeSpawn_T::WaterPotablePackaged:
		return Game_Economy::CargoType_T::WaterPotablePackaged;
		break;
	case Game_Economy::CargoTypeSpawn_T::NH3:
		return Game_Economy::CargoType_T::NH3;
		break;
	case Game_Economy::CargoTypeSpawn_T::Cl2:
		return Game_Economy::CargoType_T::Cl2;
		break;
	case Game_Economy::CargoTypeSpawn_T::HF:
		return Game_Economy::CargoType_T::HF;
		break;
	case Game_Economy::CargoTypeSpawn_T::COCl2:
		return Game_Economy::CargoType_T::COCl2;
		break;
	case Game_Economy::CargoTypeSpawn_T::H2S04:
		return Game_Economy::CargoType_T::H2S04;
		break;
	case Game_Economy::CargoTypeSpawn_T::HCl:
		return Game_Economy::CargoType_T::HCl;
		break;
	case Game_Economy::CargoTypeSpawn_T::H2O2:
		return Game_Economy::CargoType_T::H2O2;
		break;
	case Game_Economy::CargoTypeSpawn_T::H3PO4:
		return Game_Economy::CargoType_T::H3PO4;
		break;
	case Game_Economy::CargoTypeSpawn_T::C2H6O2:
		return Game_Economy::CargoType_T::C2H6O2;
		break;
	case Game_Economy::CargoTypeSpawn_T::C2H5OH:
		return Game_Economy::CargoType_T::C2H5OH;
		break;
	case Game_Economy::CargoTypeSpawn_T::C3H7OH:
		return Game_Economy::CargoType_T::C3H7OH;
		break;
	case Game_Economy::CargoTypeSpawn_T::CH3OH:
		return Game_Economy::CargoType_T::CH3OH;
		break;
	case Game_Economy::CargoTypeSpawn_T::C4H9OH:
		return Game_Economy::CargoType_T::C4H9OH;
		break;
	case Game_Economy::CargoTypeSpawn_T::C6H5OH:
		return Game_Economy::CargoType_T::C6H5OH;
		break;
	case Game_Economy::CargoTypeSpawn_T::CH3C6H4OH:
		return Game_Economy::CargoType_T::CH3C6H4OH;
		break;
	case Game_Economy::CargoTypeSpawn_T::C8H9OH:
		return Game_Economy::CargoType_T::C8H9OH;
		break;
	case Game_Economy::CargoTypeSpawn_T::CaO:
		return Game_Economy::CargoType_T::CaO;
		break;
	case Game_Economy::CargoTypeSpawn_T::KCl:
		return Game_Economy::CargoType_T::KCl;
		break;
	case Game_Economy::CargoTypeSpawn_T::Na2CO3:
		return Game_Economy::CargoType_T::Na2CO3;
		break;
	case Game_Economy::CargoTypeSpawn_T::NaOH:
		return Game_Economy::CargoType_T::NaOH;
		break;
	case Game_Economy::CargoTypeSpawn_T::NH4NO3:
		return Game_Economy::CargoType_T::NH4NO3;
		break;
	case Game_Economy::CargoTypeSpawn_T::CaCO3:
		return Game_Economy::CargoType_T::CaCO3;
		break;
	case Game_Economy::CargoTypeSpawn_T::Ca_MgCO3_2:
		return Game_Economy::CargoType_T::Ca_MgCO3_2;
		break;
	case Game_Economy::CargoTypeSpawn_T::CaSO4_2H2O:
		return Game_Economy::CargoType_T::CaSO4_2H2O;
		break;
	case Game_Economy::CargoTypeSpawn_T::FlyAsh:
		return Game_Economy::CargoType_T::FlyAsh;
		break;
	case Game_Economy::CargoTypeSpawn_T::CementClinker:
		return Game_Economy::CargoType_T::CementClinker;
		break;
	case Game_Economy::CargoTypeSpawn_T::Ca5_PO4_3F:
		return Game_Economy::CargoType_T::Ca5_PO4_3F;
		break;
	case Game_Economy::CargoTypeSpawn_T::CO_NH2_2:
		return Game_Economy::CargoType_T::CO_NH2_2;
		break;
	case Game_Economy::CargoTypeSpawn_T::C6H6:
		return Game_Economy::CargoType_T::C6H6;
		break;
	case Game_Economy::CargoTypeSpawn_T::NaC2H3O2Bulk:
		return Game_Economy::CargoType_T::NaC2H3O2Bulk;
		break;
	case Game_Economy::CargoTypeSpawn_T::K2Cr2O7Bulk:
		return Game_Economy::CargoType_T::K2Cr2O7Bulk;
		break;
	case Game_Economy::CargoTypeSpawn_T::K2Cr2O7Packaged:
		return Game_Economy::CargoType_T::K2Cr2O7Packaged;
		break;
	case Game_Economy::CargoTypeSpawn_T::CaCl2:
		return Game_Economy::CargoType_T::CaCl2;
		break;
	case Game_Economy::CargoTypeSpawn_T::AlCl3:
		return Game_Economy::CargoType_T::AlCl3;
		break;
	case Game_Economy::CargoTypeSpawn_T::TiO2:
		return Game_Economy::CargoType_T::TiO2;
		break;
	case Game_Economy::CargoTypeSpawn_T::LPG:
		return Game_Economy::CargoType_T::LPG;
		break;
	case Game_Economy::CargoTypeSpawn_T::Petrol:
		return Game_Economy::CargoType_T::Petrol;
		break;
	case Game_Economy::CargoTypeSpawn_T::Diesel:
		return Game_Economy::CargoType_T::Diesel;
		break;
	case Game_Economy::CargoTypeSpawn_T::Aluminium:
		return Game_Economy::CargoType_T::Aluminium;
		break;
	case Game_Economy::CargoTypeSpawn_T::AluminiumCoil:
		return Game_Economy::CargoType_T::AluminiumCoil;
		break;
	case Game_Economy::CargoTypeSpawn_T::Copper:
		return Game_Economy::CargoType_T::Copper;
		break;
	case Game_Economy::CargoTypeSpawn_T::Brass:
		return Game_Economy::CargoType_T::Brass;
		break;
	case Game_Economy::CargoTypeSpawn_T::BrassCoil:
		return Game_Economy::CargoType_T::BrassCoil;
		break;
	case Game_Economy::CargoTypeSpawn_T::Steel:
		return Game_Economy::CargoType_T::Steel;
		break;
	case Game_Economy::CargoTypeSpawn_T::SteelCoil:
		return Game_Economy::CargoType_T::SteelCoil;
		break;
	case Game_Economy::CargoTypeSpawn_T::StainlessSteel:
		return Game_Economy::CargoType_T::StainlessSteel;
		break;
	case Game_Economy::CargoTypeSpawn_T::StainlessSteelCoil:
		return Game_Economy::CargoType_T::StainlessSteelCoil;
		break;
	case Game_Economy::CargoTypeSpawn_T::Wheat:
		return Game_Economy::CargoType_T::Wheat;
		break;
	case Game_Economy::CargoTypeSpawn_T::Corn:
		return Game_Economy::CargoType_T::Corn;
		break;
	case Game_Economy::CargoTypeSpawn_T::Soy:
		return Game_Economy::CargoType_T::Soy;
		break;
	case Game_Economy::CargoTypeSpawn_T::Barley:
		return Game_Economy::CargoType_T::Barley;
		break;
	case Game_Economy::CargoTypeSpawn_T::Oats:
		return Game_Economy::CargoType_T::Oats;
		break;
	case Game_Economy::CargoTypeSpawn_T::Sorghum:
		return Game_Economy::CargoType_T::Sorghum;
		break;
	case Game_Economy::CargoTypeSpawn_T::Rice:
		return Game_Economy::CargoType_T::Rice;
		break;
	case Game_Economy::CargoTypeSpawn_T::SoftwoodsPackaged:
		return Game_Economy::CargoType_T::SoftwoodsPackaged;
		break;
	case Game_Economy::CargoTypeSpawn_T::HardwoodsPackaged:
		return Game_Economy::CargoType_T::HardwoodsPackaged;
		break;
	case Game_Economy::CargoTypeSpawn_T::SoftwoodsPlanks:
		return Game_Economy::CargoType_T::SoftwoodsPlanks;
		break;
	case Game_Economy::CargoTypeSpawn_T::HardwoodsPlanks:
		return Game_Economy::CargoType_T::HardwoodsPlanks;
		break;
	case Game_Economy::CargoTypeSpawn_T::SoftwoodsChips:
		return Game_Economy::CargoType_T::SoftwoodsChips;
		break;
	case Game_Economy::CargoTypeSpawn_T::HardwoodsChips:
		return Game_Economy::CargoType_T::HardwoodsChips;
		break;
	case Game_Economy::CargoTypeSpawn_T::PaperRoll:
		return Game_Economy::CargoType_T::PaperRoll;
		break;
	case Game_Economy::CargoTypeSpawn_T::PaperCardRoll:
		return Game_Economy::CargoType_T::PaperCardRoll;
		break;
	case Game_Economy::CargoTypeSpawn_T::PE:
		return Game_Economy::CargoType_T::PE;
		break;
	case Game_Economy::CargoTypeSpawn_T::HDPE:
		return Game_Economy::CargoType_T::HDPE;
		break;
	case Game_Economy::CargoTypeSpawn_T::PP:
		return Game_Economy::CargoType_T::PP;
		break;
	case Game_Economy::CargoTypeSpawn_T::PVC:
		return Game_Economy::CargoType_T::PVC;
		break;
	case Game_Economy::CargoTypeSpawn_T::ABS:
		return Game_Economy::CargoType_T::ABS;
		break;
	case Game_Economy::CargoTypeSpawn_T::Cement:
		return Game_Economy::CargoType_T::Cement;
		break;
	case Game_Economy::CargoTypeSpawn_T::BaggedCement:
		return Game_Economy::CargoType_T::BaggedCement;
		break;
	case Game_Economy::CargoTypeSpawn_T::Sand:
		return Game_Economy::CargoType_T::Sand;
		break;
	case Game_Economy::CargoTypeSpawn_T::Gravel:
		return Game_Economy::CargoType_T::Gravel;
		break;
	case Game_Economy::CargoTypeSpawn_T::SmallElectronics:
		return Game_Economy::CargoType_T::SmallElectronics;
		break;
	case Game_Economy::CargoTypeSpawn_T::MediumElectronics:
		return Game_Economy::CargoType_T::MediumElectronics;
		break;
	case Game_Economy::CargoTypeSpawn_T::LargeElectronics:
		return Game_Economy::CargoType_T::LargeElectronics;
		break;
	case Game_Economy::CargoTypeSpawn_T::WhiteGoods:
		return Game_Economy::CargoType_T::WhiteGoods;
		break;
	case Game_Economy::CargoTypeSpawn_T::MachineComponentsM:
		return Game_Economy::CargoType_T::MachineComponentsM;
		break;
	case Game_Economy::CargoTypeSpawn_T::MachineComponentsL:
		return Game_Economy::CargoType_T::MachineComponentsL;
		break;
	case Game_Economy::CargoTypeSpawn_T::CommercialMachinery:
		return Game_Economy::CargoType_T::CommercialMachinery;
		break;	
	case Game_Economy::CargoTypeSpawn_T::HeavyComercialMachinery:
		return Game_Economy::CargoType_T::HeavyComercialMachinery;
		break;
	case Game_Economy::CargoTypeSpawn_T::IndustrialMachinery:
		return Game_Economy::CargoType_T::IndustrialMachinery;
		break;
	case Game_Economy::CargoTypeSpawn_T::SmallGoods:
		return Game_Economy::CargoType_T::SmallGoods;
		break;
	case Game_Economy::CargoTypeSpawn_T::PackagedMeat:
		return Game_Economy::CargoType_T::PackagedMeat;
		break;
	case Game_Economy::CargoTypeSpawn_T::CannedGoods:
		return Game_Economy::CargoType_T::CannedGoods;
		break;
	case Game_Economy::CargoTypeSpawn_T::Cereals:
		return Game_Economy::CargoType_T::Cereals;
		break;
	case Game_Economy::CargoTypeSpawn_T::FreshFruit:
		return Game_Economy::CargoType_T::FreshFruit;
		break;
	case Game_Economy::CargoTypeSpawn_T::LiquifiedPoop:
		return Game_Economy::CargoType_T::LiquifiedPoop;
		break;
	case Game_Economy::CargoTypeSpawn_T::SoftservePoop:
		return Game_Economy::CargoType_T::SoftservePoop;
		break;
	case Game_Economy::CargoTypeSpawn_T::HardPoop:
		return Game_Economy::CargoType_T::HardPoop;
		break;
	case Game_Economy::CargoTypeSpawn_T::DriedPoop:
		return Game_Economy::CargoType_T::DriedPoop;
		break;
	default:
		return Game_Economy::CargoType_T::Water;
		break;
	}
}

Game_Economy::CargoType_T Game_Economy::SpawnCargo(const uint32_t& _type)
{
	return Game_Economy::SpawnCargo(
		static_cast<Game_Economy::CargoTypeSpawn_T>(_type));
}

Game_Economy::CargoType_T Game_Economy::SpawnRandomCargo(
	Game_Math::GameRandomDev<uint32_t>& _random_device)
{
	auto _cargo_id = _random_device.Grab();
	return SpawnCargo(_cargo_id);
}

Game_Economy::CargoType_T Game_Economy::SpawnRandomCargoRange(
	Game_Math::GameRandomDev<uint32_t>& _random_device, 
	uint32_t _lower, uint32_t _upper)
{
	_random_device.Redistribute(_lower, _upper);
	auto _cargo_id = _random_device.Grab();
	return SpawnCargo(_cargo_id);
}

Game_Economy::CargoType_T Game_Economy::SpawnRandomCargoClass(
	Game_Math::GameRandomDev<uint32_t>& _random_device, 
	CargoClassSpawn_T _class)
{
	auto class_range = static_cast<uint32_t>(_class);
	uint32_t lower = class_range & 0x0000FFFF;
	uint32_t upper = class_range >> 16;

	return SpawnRandomCargoRange(_random_device,
		lower, upper);
}
