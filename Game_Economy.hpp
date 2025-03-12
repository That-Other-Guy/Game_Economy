#pragma once

#ifndef _GAME_ECONOMY_HPP_
#define _GAME_ECONOMY_HPP_

bool Game_Economy_Static_Link_Test(bool _in);

#include <string>
#include <vector>
#include <utility>
#include <stdexcept>
#include <memory>

// The A = L + E Economy

namespace Economy
{
	// unit id contains density mass per volume - > g/L
	enum class Commodity_ID : unsigned int
	{
		Cash = 0,
		Liabilty = 1,
		Water = 1000,
		Milk = 1050,
		Diesel = 850,
		wheat = 790,
	};

	class BalanceSheetEntry
	{
	public:
		BalanceSheetEntry();
		BalanceSheetEntry(
			const int& _value,
			const unsigned int& _day_of_entry,
			const std::string& _entry_note = "No information recorded!");
		BalanceSheetEntry(
			const int& _value,
			const unsigned int& _day_of_entry,
			const unsigned int& _transaction_id,
			const std::string& _entry_note = "No information recorded!");
		BalanceSheetEntry(const BalanceSheetEntry& _other);
		const unsigned int GetEntryDate();
		const int GetValue() const;
		const std::string PrintEntryNote() const;
		const unsigned int GetTransactionIdentifier();
	private:
		const unsigned int day_of_entry; // Game day of entry
		const int value;
		const std::string entry_note;
		const unsigned int transaction_id;
	public:
		const int operator + (const BalanceSheetEntry& _rhs) const;
		const int operator - (const BalanceSheetEntry& _rhs) const;
		const bool operator == (const BalanceSheetEntry& _rhs) const;
	};

	typedef BalanceSheetEntry Asset;
	typedef BalanceSheetEntry Liability;
	typedef BalanceSheetEntry Equity;

	class Commodity
	{
	public:
		Commodity_ID Id;
		int quantity;
	public:
		Commodity(Commodity_ID _id)
			: Id(_id), quantity(0)
		{}
		Commodity(Commodity_ID _id, int _qty)
			: Id(_id), quantity(_qty)
		{}
	};

	class Obligation
	{
	public:
		Obligation(
			const unsigned int& _entity_identifier,
			const Commodity& _commodity,
			const unsigned int& _due_date
		);
		const unsigned int entity_identifier;
		const Commodity commodity;
		const unsigned int due_date;
	};

	class Transaction
	{
	private:
		const unsigned int transaction_id;
		std::pair<bool, bool> transaction_is_Settled;
	private:
		Obligation PartyA;
		Obligation PartyB;
	public:
		Transaction();
		Transaction(
			const std::pair<const unsigned int, Commodity>& _PartyA,
			const std::pair<const unsigned int, Commodity>& _PartyB
		);
		bool FulfillObligation(const Obligation _obligation);


	};

	class BalanceSheet
	{
	public:
		BalanceSheet();
	private:
		std::vector<Asset> Assets_Current;
		std::vector<Asset> Assets_Non_Current;
		std::vector<Asset> Assets_Receivable;
		std::vector<Asset> Assets_Other;
		std::vector<Liability> Liability_Loans;
		std::vector<Liability> Liability_TaxWitheld;
		std::vector<Liability> Liability_Payable;
		std::vector<Liability> Liability_Other;
		std::vector<Equity> Equity_Owner;
		std::vector<Equity> Equity_Shares;
		std::vector<Equity> Equity_Retained_Earnings;
		bool BalanceSheetIsBalanced();
	public:
	};



	class Entity
	{
	private:
		int identifier;
		std::vector<Commodity> wallet;
	private:
		std::pair<bool, Commodity*> FindCommodity(const Commodity_ID& _id);
	public:
		Entity(int _identifier);
		int GetID() const;
		bool Transact(const Commodity& _in, const Commodity& _out);
		bool CheckBalance(const Commodity& _commodity);
		std::string PrintBalance(const Commodity_ID& _id);
		bool Transact(const Commodity& _commodity);
	};

	class Ledger
	{
	private:
		std::unique_ptr<std::vector<Entity>> Economic_Entities;
		int entity_id_gen;
	public:
		Ledger();
		~Ledger();
		std::pair<bool, bool> ProcessExchange(
			int& _id_lhs, const Commodity& _lhs_exchange,
			int& _id_rhs, const Commodity& _rhs_exchange
		);
		bool GiftComodity(
			int& _id, const Commodity& _commodity, bool _safe = false
		);
		int OpenAccount();
		bool CloseAccount(int _id);
		bool Trade(int _id_partyA, Commodity& _commodityA,
			int _id_partyB, Commodity& _commodityB);

	private:
		std::pair<Entity*, Entity*> FindAccounts(int& _id_lhs, int& _id_rhs);
		std::pair<bool, Entity*> FindAccount(int& _id);
		std::pair<bool, bool> ProcessExchange(
			Entity& _lhs, const Commodity& _lhs_exchange,
			Entity& _rhs, const Commodity& _rhs_exchange
		);
	};
}

#endif // !_GAME_ECONOMY_HPP_
