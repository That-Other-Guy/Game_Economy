#pragma once
#ifndef _GAMECARGO_HPP_
#define _GAMECARGO_HPP_

#include "CombinationCargo.hpp"

std::pair<Game_Economy::CargoReturn, std::string>
	MoveBulkCargo(
	const Game_Economy::Objects::BulkCargo& _source,
	const Game_Economy::Objects::BulkCargo& _destination,
	float _volume, bool _clean_source = false, bool _ext_string = false
);

#endif // !_GAMECARGO_HPP_