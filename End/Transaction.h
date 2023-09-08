#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <ctime>
#include <string>
using namespace std;

class Transaction {
private:
    int amount;
    string category;
    time_t transactionTime;

public:
    Transaction(int amount, const string& category, const string& comment);
    int GetAmount() const;
    const string& GetCategory() const;
    time_t GetTime() const;
};

#endif // TRANSACTION_H
