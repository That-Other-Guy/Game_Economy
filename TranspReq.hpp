#pragma once
#ifndef _TRANSPREQ_HPP_
#define _TRANSPREQ_HPP_

#include "Cargo_T.hpp"
#include <Game_Math/Common.hpp>
#include <initializer_list>

namespace Game_Economy
{
	class TranspReq
	{
	public:
		TranspReq(const TranspReq_T& _requirements)
			:
			requirements(static_cast<uint32_t>(_requirements)) {
		}
		TranspReq(
			const std::initializer_list<Game_Economy::TranspReq_T> _requirements);
	private:
		uint32_t requirements; // Member Variable
	private: // Private Member Functions
		uint32_t TheseReq() const;
		uint32_t ThoseReq(const uint32_t _candidate) const;
		std::string Print(const uint32_t _print) const;
	public: // Getters
		TranspReq_T GetTransportReq() const;
	public: // Get Print Strings
		std::string PrintTransportReq() const;
	public: // Boolean and Comparisons
		bool IsCompatible(const CargoType_T& _candidate_cargo) const;
		bool IsCompatible(const TranspReq_T& _candidate_container) const;
	public: // Overloads
		bool operator == (const TranspReq& _rhs) const
		{
			return (this->requirements == _rhs.requirements);
		}
		bool operator == (const CargoType_T& _rhs) const
		{
			return IsCompatible(_rhs);
		}
		bool operator == (const TranspReq_T& _rhs) const
		{
			return IsCompatible(_rhs);
		}
	};
	
}
#endif // !_TRANSPREQ_HPP_
