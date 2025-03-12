#include "Game_Economy.hpp"
// Game_Economy.cpp : Defines the functions for the static library.
//

bool Game_Economy_Static_Link_Test(bool _in)
{
	return _in;
}


Economy::BalanceSheetEntry::BalanceSheetEntry()
	: value(0), day_of_entry(1), entry_note("Default Constructor"),
	transaction_id(0)
{
}

Economy::BalanceSheetEntry::BalanceSheetEntry(
	const int& _value,
	const unsigned int& _day_of_entry,
	const std::string& _entry_note)
	: value(_value), day_of_entry(_day_of_entry), entry_note(_entry_note),
	transaction_id(0)
{
	if (day_of_entry < 1)
		throw std::invalid_argument("BalanceSheetEntry() - Day of entry can not be less than 1!");
}

Economy::BalanceSheetEntry::BalanceSheetEntry(const int& _value, const unsigned int& _day_of_entry, const unsigned int& _transaction_id, const std::string& _entry_note)
	: value(_value), day_of_entry(_day_of_entry), entry_note(_entry_note),
	transaction_id(_transaction_id)
{
	if (day_of_entry < 1)
		throw std::invalid_argument("BalanceSheetEntry() - Day of entry can not be less than 1!");
	if (transaction_id == 0)
		throw std::invalid_argument("BalanceSheetEntry() - Assigned transaction_id can not be zero!");
}

Economy::BalanceSheetEntry::BalanceSheetEntry(const BalanceSheetEntry& _other)
	: value(_other.value), day_of_entry(_other.day_of_entry), entry_note(_other.entry_note),
	transaction_id(_other.transaction_id)
{
}

const unsigned int Economy::BalanceSheetEntry::GetEntryDate()
{
	return day_of_entry;
}

const int Economy::BalanceSheetEntry::GetValue() const
{
	return value;
}

const std::string Economy::BalanceSheetEntry::PrintEntryNote() const
{
	return entry_note;
}

const unsigned int Economy::BalanceSheetEntry::GetTransactionIdentifier()
{
	return transaction_id;
}

const int Economy::BalanceSheetEntry::operator+(const BalanceSheetEntry& _rhs) const
{
	return this->value + _rhs.value;
}

const int Economy::BalanceSheetEntry::operator-(const BalanceSheetEntry& _rhs) const
{
	return this->value - _rhs.value;
}

const bool Economy::BalanceSheetEntry::operator==(const BalanceSheetEntry& _rhs) const
{
	return this->value == _rhs.value;
}

// Commodity

std::pair<bool, Economy::Commodity*> Economy::Entity::FindCommodity(
	const Economy::Commodity_ID& _id
)
{
	for (auto& commodity : wallet)
		if (commodity.Id == _id)
			return { true, &commodity };

	return { false, nullptr };
}

// Obligation

Economy::Obligation::Obligation(
	const unsigned int& _entity_identifier,
	const Commodity& _commodity,
	const unsigned int& _due_date
)
	:
	entity_identifier(_entity_identifier),
	commodity(_commodity),
	due_date(_due_date)
{
}

// Transaction






Economy::Entity::Entity(int _identifier)
	: identifier(_identifier)
{
}

int Economy::Entity::GetID() const
{
	return identifier;
}

bool Economy::Entity::Transact(const Commodity& _in, const Commodity& _out)
{
	Economy::Commodity out = _out;
	out.quantity = -out.quantity;

	return (Transact(_in) && Transact(_out));
}

bool Economy::Entity::CheckBalance(const Commodity& _commodity)
{
	auto found_commodity = FindCommodity(_commodity.Id);
	return (found_commodity.first &&
		_commodity.quantity <= found_commodity.second->quantity);
}

std::string Economy::Entity::PrintBalance(const Commodity_ID& _id)
{
	auto found_commodity = FindCommodity(_id);
	if (found_commodity.first)
		return std::to_string(found_commodity.second->quantity);

	return "0";
}


bool Economy::Entity::Transact(const Commodity& _commodity)
{
	auto found_commodity = FindCommodity(_commodity.Id);
	if (found_commodity.first)
	{
		Commodity* commodity_ptr = found_commodity.second;
		int new_balance =
			commodity_ptr->quantity + _commodity.quantity;
		if (new_balance < 0) // can't have negative qty.
			return false;

		commodity_ptr->quantity = new_balance;
		return true;
	}

	else
	{
		wallet.push_back(_commodity);
	}
	return true;
}

Economy::Ledger::Ledger()
	: Economic_Entities(std::make_unique<std::vector<Economy::Entity>>()), entity_id_gen(0)
{
}

Economy::Ledger::~Ledger() = default;

std::pair<bool, bool> Economy::Ledger::ProcessExchange(int& _id_lhs, const Commodity & _lhs_exchange, int& _id_rhs, const Commodity & _rhs_exchange)
{
	if (_id_lhs == _id_rhs)
		throw std::runtime_error("Economic entities can not self exchange!");

	auto Lhs_Rhs = FindAccounts(_id_lhs, _id_rhs);

	if (Lhs_Rhs.first == nullptr || Lhs_Rhs.second == nullptr)
		throw std::runtime_error("Can not transact. One or more entities does not exist!");

	return ProcessExchange(
		*Lhs_Rhs.first, _lhs_exchange,
		*Lhs_Rhs.second, _rhs_exchange
	);
}

bool Economy::Ledger::GiftComodity(int& _id, const Commodity & _commodity, bool _safe)
{
	if (_safe)
	{
		auto Acc = FindAccount(_id);
		if (Acc.first)
		{
			Acc.second->Transact(_commodity);
			return true;
		}
	}
	return false;
}

int Economy::Ledger::OpenAccount()
{
	int new_id = entity_id_gen;
	if (!Economic_Entities)
		throw std::runtime_error("Economic_Entities ledger is null pointer!");

	Economic_Entities.get()->emplace_back(new_id);
	entity_id_gen++;
	return new_id;
}

bool Economy::Ledger::CloseAccount(int _id)
{
	auto it = std::find_if(
		Economic_Entities.get()->begin(),
		Economic_Entities.get()->end(),
		[&](const Economy::Entity& entity)
		{
			return entity.GetID() == _id;
		}
	);

	if (it != Economic_Entities.get()->end())
	{
		Economic_Entities.get()->erase(it);
		return true;
	}
	return false;
}

std::pair<Economy::Entity*, Economy::Entity*> Economy::Ledger::FindAccounts(int& _id_lhs, int& _id_rhs)
{
	Entity* _lhs = nullptr;
	Entity* _rhs = nullptr;
	for (auto& entity : *Economic_Entities)
	{
		if (_id_lhs == entity.GetID())
			_lhs = &entity;

		if (_id_rhs == entity.GetID())
			_rhs = &entity;
	}
	return { _lhs, _rhs };
}

std::pair<bool, Economy::Entity*> Economy::Ledger::FindAccount(int& _id)
{
	Entity* _acc = nullptr;
	for (auto& entity : *Economic_Entities)
	{
		if (_id == entity.GetID())
			_acc = &entity;
	}
	if (_acc == nullptr)
		return { false, _acc };

	return { true, _acc };
}

std::pair<bool, bool> Economy::Ledger::ProcessExchange(
	Entity & _lhs, const Commodity & _lhs_exchange,
	Entity & _rhs, const Commodity & _rhs_exchange)
{
	if (&_lhs == &_rhs)
		throw std::runtime_error("Economic entities can not self exchange!");

	bool return_lhs = _lhs.CheckBalance(_lhs_exchange);
	bool return_rhs = _rhs.CheckBalance(_rhs_exchange);

	if (!(return_lhs && return_rhs))
		return { return_lhs, return_rhs };

	_lhs.Transact(_rhs_exchange, _lhs_exchange);
	_rhs.Transact(_lhs_exchange, _rhs_exchange);

	return { true, true };
}