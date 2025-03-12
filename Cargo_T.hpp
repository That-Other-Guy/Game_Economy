#pragma once
#ifndef _CARGO_T_HPP_
#define _CARGO_T_HPP_

#include <cstdint>
#include <Game_Math/GameRandom.hpp>

namespace Game_Economy
{
	namespace Constants
	{
		static constexpr int transport_req_shift = 14;
		static constexpr uint32_t transport_req_lsb = 1 << transport_req_shift;
	}

	/*
	* Transport Requirements flags are orred with CargoType_T enums.
	* TranspReq_T are unique flags restricted to upper 18 bits so
	* that is may be combined with other Types for comparisons eg.
	* TranspReq_T | CargoType_T provides material volumetric density
	* as well as transport requirements.
	*/
	enum class TranspReq_T : uint32_t
	{
		NotTransportable = Constants::transport_req_lsb, // Bit 14
		Sealed = Constants::transport_req_lsb << 1,

		Rail = Constants::transport_req_lsb << 2,
		IBC = Constants::transport_req_lsb << 3,
		Pallet = Constants::transport_req_lsb << 4,
		Covered = Constants::transport_req_lsb << 5,

		LiningOrFoodsafe = Constants::transport_req_lsb << 6,
		Hazardous = Constants::transport_req_lsb << 7,
		Liquid = Constants::transport_req_lsb << 8,
		CompressedGas = Constants::transport_req_lsb << 9,

		Granular = Constants::transport_req_lsb << 10,
		Powder = Constants::transport_req_lsb << 11,
		Aggregate = Constants::transport_req_lsb << 12,
		WoodProduct = Constants::transport_req_lsb << 13,

		PackagedSmall5 = Constants::transport_req_lsb << 14, //5L
		PackagedMedium125 = Constants::transport_req_lsb << 15, //125L
		PackagedLarge1000 = Constants::transport_req_lsb << 16, //1m3
		PackagedExtraLarge4000 = Constants::transport_req_lsb << 17, //4m3

		MaskFlags = 0xFFFFFFFFu << Constants::transport_req_shift
	};
	/*
		*Cargo types enums values are orred with TranspReq_T enums.
		* CargoType_T is restricted to lower 14 bits.
		* therefore material density values(unsigned) less than ~16, 000.
		* CargoType_T | TranspReq_T provides material volumetric density
		* as well as transport requirements.
	*/
	enum class CargoType_T : uint32_t
	{
		Clean = 0,

		NotTransportable = TranspReq_T::NotTransportable,
		Sealed = TranspReq_T::Sealed,

		Rail = TranspReq_T::Rail,
		IBC = TranspReq_T::IBC,
		Pallet = TranspReq_T::Pallet,
		Covered = TranspReq_T::Covered,

		LiningOrFoodsafe = TranspReq_T::LiningOrFoodsafe,
		Hazardous = TranspReq_T::Hazardous,
		Liquid = TranspReq_T::Liquid,
		CompressedGas = TranspReq_T::CompressedGas,

		Granular = TranspReq_T::Granular,//1
		Powder = TranspReq_T::Powder,//2
		Aggregate = TranspReq_T::Aggregate, //4
		WoodProduct = TranspReq_T::WoodProduct, //8

		PackagedSmall5 = TranspReq_T::PackagedSmall5, //1
		PackagedMedium125 = TranspReq_T::PackagedMedium125, //2
		PackagedLarge1000 = TranspReq_T::PackagedLarge1000, //4
		PackagedExtraLarge4000 = TranspReq_T::PackagedExtraLarge4000, //8

		IsPackaged = ((PackagedSmall5 | PackagedMedium125) | PackagedLarge1000) | PackagedExtraLarge4000,

		TranspReqMask = TranspReq_T::MaskFlags,
		// Package Volumes Multipliers for movement quanitites

		Volume = 1u,
		PackagedS = 5u,
		PackagedM = 125u,
		PackagedL = 1000u,
		PackagedXL = 4000u,

		// Bit flags are REQUIREMENTS.
		// ALL MUST BE MET to be compatible with CARGOCONTAINER
		// Liquids
		Water = 1001u | Liquid, //Non Potable Water
		WaterPotableBulk = 1000u | IBC | Liquid | LiningOrFoodsafe, //Potable Water
		WaterPotablePackaged = 1000u | PackagedSmall5, //Potable Water
		// Chemicals
		NH3 = 690u | LiningOrFoodsafe | Rail | Hazardous | CompressedGas, //Anhydrous Ammonia
		Cl2 = 1560u | LiningOrFoodsafe | Rail | Hazardous | CompressedGas, //Chlorine
		HF = 988u | LiningOrFoodsafe | Rail | Hazardous | CompressedGas, //Hydrogen Flouride
		COCl2 = 1360u | LiningOrFoodsafe | Rail | Hazardous | Liquid, //Phosgene
		H2S04 = 1840 | LiningOrFoodsafe | Rail | Hazardous | Liquid, //Sulphuric Acid

		HCl = 1200u | LiningOrFoodsafe | Hazardous | Liquid, //Hydrocholoric Acid
		H2O2 = 1400u | LiningOrFoodsafe | Hazardous | Liquid, //Hydrogen Peroxide
		H3PO4 = 1850u | LiningOrFoodsafe | Hazardous | Liquid, //Phosphuric Acid
		C2H6O2 = 1110u | LiningOrFoodsafe | Rail | Hazardous | Liquid, //Ethylene Glycol

		C2H5OH = 793u | Hazardous | Liquid, //Ethanol
		C3H7OH = 800u | Hazardous | Liquid, //Propanol
		CH3OH = 790u | Hazardous | Liquid, //Methanol
		C4H9OH = 810u | Hazardous | Liquid, //Butanol

		C6H5OH = 1070u | LiningOrFoodsafe | Hazardous | Liquid, //Phenol
		CH3C6H4OH = 1040u | LiningOrFoodsafe | Hazardous | Liquid, //Cresol
		C8H9OH = 960u | LiningOrFoodsafe | Hazardous | Liquid, //Xylenol

		CaO = (((980u | LiningOrFoodsafe) | Covered) | Hazardous) | Powder, //Calcium Oxide
		KCl = 2000u | Covered | Granular, //Potasium Chloride
		Na2CO3 = 1110u | Covered | Granular, //Sodium Bicarbonate
		NaOH = 2130u | Covered | Hazardous | Granular, //Sodium Hydroxide
		NH4NO3 = 1720u | LiningOrFoodsafe | Rail | Covered | Hazardous | Granular, // Ammonium Nitrate

		CaCO3 = 2700u | Covered | Granular | Aggregate, //Calcium Carbonate (Limestone)
		Ca_MgCO3_2 = 2900u | Covered | Granular | Aggregate, //Dolostone
		CaSO4_2H2O = 2300u | Covered | Granular | Aggregate, //Gypsum
		FlyAsh = 2100u | Covered | Hazardous | Powder,
		CementClinker = 1500u | Covered | Granular,
		Ca5_PO4_3F = 2700u | Covered | Aggregate, //Phosphate Rock
		CO_NH2_2 = 770u | Covered | Granular, //Urea

		C6H6 = 880u | LiningOrFoodsafe | Rail | Hazardous | Liquid, //Benzene
		NaC2H3O2Bulk = 1530u | Covered | Granular, //Sodium Acetate		
		K2Cr2O7Bulk = 2690u | LiningOrFoodsafe | Sealed | Covered | Hazardous | Granular, //Potassium Dichromate
		K2Cr2O7Packaged = 2690u | Covered | Hazardous | PackagedMedium125, //Potassium Dichromate

		CaCl2 = 2110u | Covered | Granular, //Calcium Chloride
		AlCl3 = 1340u | Covered | Hazardous | Granular, //(Aluminum Chloride)
		TiO2 = 4000u | LiningOrFoodsafe | Sealed | Covered | Hazardous | Granular, //Titanium Dioxide

		// Fuel
		LPG = 580u | Hazardous | CompressedGas,
		Petrol = 730u | Sealed | Hazardous | Liquid,
		Diesel = 855u | Sealed | Hazardous | Liquid,
		//Kerosene,
		//Fuel Oil,
		//Heavy Fuel Oil,
		//Propane

		// Metals
		Aluminium = 2700u | PackagedMedium125,
		AluminiumCoil = 2700u | Rail | PackagedExtraLarge4000,
		Copper = 8960u | PackagedMedium125,
		Brass = 8600u | PackagedMedium125,
		BrassCoil = 8600u | Rail | PackagedLarge1000,
		Steel = 8100u | PackagedMedium125,
		SteelCoil = 8100u | Rail | PackagedExtraLarge4000,
		StainlessSteel = 7985u | PackagedMedium125,
		StainlessSteelCoil = 7985u | Rail | PackagedExtraLarge4000,

		// Grains
		Wheat = 770u | Covered | LiningOrFoodsafe | Granular,
		Corn = 720u | Covered | LiningOrFoodsafe | Granular,
		Soy = 750u | Covered | LiningOrFoodsafe | Granular,
		Barley = 655u | Covered | LiningOrFoodsafe | Granular,
		Oats = 439u | Covered | LiningOrFoodsafe | Granular,
		Sorghum = 789u | Covered | LiningOrFoodsafe | Granular,
		Rice = 858u | Covered | LiningOrFoodsafe | Granular,

		// Timber
		SoftwoodsPackaged = 501u | PackagedMedium125,
		HardwoodsPackaged = 751u | PackagedMedium125,
		SoftwoodsPlanks = 502u | Rail | PackagedLarge1000,
		HardwoodsPlanks = 752u | Rail | PackagedLarge1000,
		SoftwoodsChips = 533u | Rail | WoodProduct | Aggregate,
		HardwoodsChips = 783u | Rail | WoodProduct | Aggregate,
		PaperRoll = 200u | Covered | PackagedLarge1000,
		PaperCardRoll = 450u | Covered | PackagedLarge1000,

		// GranularPlastics
		PE = 919u | Covered | Granular, //Polyethylene
		HDPE = 949u | Covered | Granular, //High Density Polyethylene
		PP = 897u | Covered | Granular, //Polypropylene
		PVC = 1431u | Covered | Granular, //Polyvinyl Chloride
		ABS = 1030u | Covered | Granular, //Acrylonitrile Butadiene Styrene

		Cement = 2400u | Covered | Powder,
		BaggedCement = 2401u | PackagedMedium125,
		Sand = 1400u | Aggregate,
		Gravel = 1300u | Aggregate,

		// Household Electronics
		SmallElectronics = 300u | Covered | PackagedSmall5,
		MediumElectronics = 450u | Covered | PackagedMedium125,
		LargeElectronics = 555u | Covered | PackagedLarge1000,
		WhiteGoods = 480u | Covered | PackagedLarge1000,

		MachineComponentsM = 3500u | PackagedMedium125,
		MachineComponentsL = 3500u | PackagedLarge1000,
		CommercialMachinery = 444u | Covered | PackagedLarge1000,
		HeavyComercialMachinery = 3200u | PackagedLarge1000,
		IndustrialMachinery = 753u | Rail | PackagedExtraLarge4000,


		// Grocery
		SmallGoods = 1180u | Covered | LiningOrFoodsafe | PackagedSmall5,
		PackagedMeat = 1080u | Covered | LiningOrFoodsafe | PackagedSmall5,
		CannedGoods = 1170u | Covered | LiningOrFoodsafe | PackagedSmall5,
		Cereals = 230u | Covered | LiningOrFoodsafe | PackagedMedium125,
		FreshFruit = 800u | Covered | LiningOrFoodsafe | PackagedMedium125,

		// Other
		LiquifiedPoop = 905u | Hazardous | Liquid,
		SoftservePoop = 1105u | Hazardous | Liquid,
		HardPoop = 1305u | Hazardous,
		DriedPoop = 605u | Hazardous | PackagedMedium125,

		CargoDensityMask = ~TranspReqMask
	};

	enum class CargoTypeSpawn_T : uint32_t
	{
		START_OF_LIST = 1u,

		START_OF_CHEMICALS_LG,
		Cl2,
		NH3,
		HF,
		HCl,
		COCl2,
		C6H6,
		END_OF_CHEMICALS_LG,

		START_OF_CHEMICALS_LIQUID,
		Water,
		H2S04,
		H2O2,
		H3PO4,
		C2H6O2,
		C2H5OH,
		C3H7OH,
		CH3OH,
		C4H9OH,
		C6H5OH,
		CH3C6H4OH,
		C8H9OH,
		CaCl2,
		END_OF_CHEMICALS_LIQUID,

		START_OF_CHEMICALS_SOLID,
		CaO,
		KCl,
		Na2CO3,
		NaOH,
		NH4NO3,
		CaCO3,
		Ca_MgCO3_2,
		CaSO4_2H2O,
		Ca5_PO4_3F,
		CO_NH2_2,
		NaC2H3O2Bulk,
		K2Cr2O7Bulk,
		K2Cr2O7Packaged,
		AlCl3,
		TiO2,
		END_OF_CHEMICALS_SOLID,


		START_OF_FUELS,
		LPG,
		Petrol,
		Diesel,
		//Kerosene,
		//FuelOil,
		//HeavyFuelOil,
		//Popane,
		END_OF_FUELS,

		START_OF_METALS,
		Aluminium,
		AluminiumCoil,
		Copper,
		Brass,
		BrassCoil,
		Steel,
		SteelCoil,
		StainlessSteel,
		StainlessSteelCoil,
		END_OF_METALS,

		START_OF_GRAINS_BULK,
		Wheat,
		Corn,
		Soy,
		Barley,
		Oats,
		Sorghum,
		Rice,
		END_OF_GRAINS_BULK,

		START_OF_WOODANDPULP,
		SoftwoodsPackaged,
		HardwoodsPackaged,
		SoftwoodsPlanks,
		HardwoodsPlanks,
		SoftwoodsChips,
		HardwoodsChips,
		PaperRoll,
		PaperCardRoll,
		END_OF_WOODANDPULP,

		START_OF_RAWPLASTICS,
		PE,
		HDPE,
		PP,
		PVC,
		ABS,
		END_OF_RAWPLASTICS,

		START_OF_CONSTRUCTION,
		FlyAsh,
		CementClinker,
		Cement,
		BaggedCement,
		Sand,
		Gravel,
		END_OF_CONSTRUCTION,

		START_OF_ELECTRICALGOODS,
		SmallElectronics,
		MediumElectronics,
		LargeElectronics,
		WhiteGoods,
		END_OF_ELECTRICALGOODS,

		START_OF_MACHINERY,
		MachineComponentsM,
		MachineComponentsL,
		CommercialMachinery,
		HeavyComercialMachinery,
		IndustrialMachinery,
		END_OF_MACHINERY,

		START_OF_POOP,
		LiquifiedPoop,
		SoftservePoop,
		HardPoop,
		DriedPoop,
		END_OF_POOP,

		START_OF_FOOD,
		WaterPotableBulk,
		WaterPotablePackaged,
		SmallGoods,
		PackagedMeat,
		CannedGoods,
		Cereals,
		FreshFruit,
		END_OF_FOOD,

		END_OF_LIST
	};

	enum class CargoClassSpawn_T : uint32_t
	{
		ChemicalsLG = 
		static_cast<uint32_t>(CargoTypeSpawn_T::START_OF_CHEMICALS_LG) + 1 | 
		(static_cast<uint32_t>(CargoTypeSpawn_T::END_OF_CHEMICALS_LG) - 1) << 16,
		ChemicalsLiquid =
		static_cast<uint32_t>(CargoTypeSpawn_T::START_OF_CHEMICALS_LIQUID) + 1 |
		(static_cast<uint32_t>(CargoTypeSpawn_T::END_OF_CHEMICALS_LIQUID) - 1) << 16,
		ChemicalsSolid =
		static_cast<uint32_t>(CargoTypeSpawn_T::START_OF_CHEMICALS_SOLID) + 1 |
		(static_cast<uint32_t>(CargoTypeSpawn_T::END_OF_CHEMICALS_SOLID) - 1) << 16,
		Fuels =
		static_cast<uint32_t>(CargoTypeSpawn_T::START_OF_FUELS) + 1 |
		(static_cast<uint32_t>(CargoTypeSpawn_T::END_OF_FUELS) - 1) << 16,
		Metals = 
		static_cast<uint32_t>(CargoTypeSpawn_T::START_OF_METALS) + 1 |
		(static_cast<uint32_t>(CargoTypeSpawn_T::END_OF_METALS) - 1) << 16,
		BulkGrains =
		static_cast<uint32_t>(CargoTypeSpawn_T::START_OF_GRAINS_BULK) + 1 |
		(static_cast<uint32_t>(CargoTypeSpawn_T::END_OF_GRAINS_BULK) - 1) << 16,
		WoodAndPulp =
		static_cast<uint32_t>(CargoTypeSpawn_T::START_OF_WOODANDPULP) + 1 |
		(static_cast<uint32_t>(CargoTypeSpawn_T::END_OF_WOODANDPULP) - 1) << 16,
		Plastics =
		static_cast<uint32_t>(CargoTypeSpawn_T::START_OF_RAWPLASTICS) + 1 |
		(static_cast<uint32_t>(CargoTypeSpawn_T::END_OF_RAWPLASTICS) - 1) << 16,
		Construction =
		static_cast<uint32_t>(CargoTypeSpawn_T::START_OF_CONSTRUCTION) + 1 |
		(static_cast<uint32_t>(CargoTypeSpawn_T::END_OF_CONSTRUCTION) - 1) << 16,
		Electrical =
		static_cast<uint32_t>(CargoTypeSpawn_T::START_OF_ELECTRICALGOODS) + 1 |
		(static_cast<uint32_t>(CargoTypeSpawn_T::END_OF_ELECTRICALGOODS) - 1) << 16,
		Machinery =
		static_cast<uint32_t>(CargoTypeSpawn_T::START_OF_MACHINERY) + 1 |
		(static_cast<uint32_t>(CargoTypeSpawn_T::END_OF_MACHINERY) - 1) << 16,
		Poop =
		static_cast<uint32_t>(CargoTypeSpawn_T::START_OF_POOP) + 1 |
		(static_cast<uint32_t>(CargoTypeSpawn_T::END_OF_POOP) - 1) << 16,
		Food =
		static_cast<uint32_t>(CargoTypeSpawn_T::START_OF_FOOD) + 1 |
		(static_cast<uint32_t>(CargoTypeSpawn_T::END_OF_FOOD) - 1) << 16,
	};


	CargoType_T SpawnCargo(const CargoTypeSpawn_T& _type);
	CargoType_T SpawnCargo(const uint32_t & _type);
	CargoType_T SpawnRandomCargo(Game_Math::GameRandomDev<uint32_t> & _random_device);
	CargoType_T SpawnRandomCargoRange(
		Game_Math::GameRandomDev<uint32_t>& _random_device,
		uint32_t _lower, uint32_t _upper);
	CargoType_T SpawnRandomCargoClass(Game_Math::GameRandomDev<uint32_t>& _random_device,
		CargoClassSpawn_T _class);
	
}

#endif // !_CARGO_T_HPP_
