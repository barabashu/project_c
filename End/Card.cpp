#include "Card.h"
#include <iostream>

using namespace std;

Card::Card(string Name, long long Number, int Sum, CardType Type, int Limit)
    : Name(Name), Number(Number), Sum(Sum), Type(Type), Limit(Limit) {
}

void Card::Deposit(int amount) {
    Sum += amount;
    cout << "Депозит " << amount << " на номер карты " << Number << ". Новый баланс: " << Sum << ".\n";
}

// card.cpp
bool Card::Withdraw(int amount) {
    if (Type == CardType::Debit && Sum - amount < 0) {
        return false;
    }
    if (Type == CardType::Credit && Sum - amount < -Limit) {
        return false;
    }
    Sum -= amount;
    AddTransaction(Transaction(-amount, "Вывод", "Баксы выведены"));
    return true;
}


void Card::PrintCard() const {
    cout << "Карта: " << Name << ", " << Number << ", $" << Sum;
    if (Type == CardType::Credit) {
        cout << ", Кредитный лимит: $" << Limit;
    }
    cout << endl;
}

void Card::AddTransaction(const Transaction& t) {
    transactions.push_back(t);
    Sum += t.GetAmount();
}

string Card::GetName() const {
    return Name;
}

vector<Transaction> Card::GetTransactions() const {
    return transactions;
}

vector<Transaction> Card::GetTransactionsInDateRange(time_t start, time_t end) const {
    vector<Transaction> result;
    for (const auto& transaction : transactions) {
        if (transaction.GetTime() >= start && transaction.GetTime() <= end) {
            result.push_back(transaction);
        }
    }
    return result;
}

void Card::PrintTransactions() const {
    cout << "Транзакции по карте: " << Number << endl;
    for (const auto& transaction : transactions) {
        cout << "Сумма: " << transaction.GetAmount()
             << ", Категория: " << transaction.GetCategory()
             << endl;
    }
}
