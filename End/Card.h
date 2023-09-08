#pragma once
#include <string>
#include <vector>
#include "Transaction.h"

using namespace std;

enum class CardType { Debit, Credit };

class Card {
private:
    string Name;
    long long Number;
    int Sum;
    CardType Type;
    int Limit;
    vector<Transaction> transactions;
public:
    Card(string Name, long long Number, int Sum, CardType Type, int Limit);
    void AddTransaction(const Transaction& t);
    void PrintCard() const;
    void Deposit(int amount);
    bool Withdraw(int amount);
    string GetName() const;
    vector<Transaction> GetTransactions() const;
    vector<Transaction> GetTransactionsInDateRange(time_t start, time_t end) const;
    void PrintTransactions() const;
    int GetSum() const { return Sum;}
    
};
