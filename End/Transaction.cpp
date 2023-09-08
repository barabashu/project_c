#include "Transaction.h"
#include <ctime>
using namespace std;

Transaction::Transaction(int amount, const string& category, const string& comment)
    : amount(amount), category(category), transactionTime(time(nullptr)) {
}

int Transaction::GetAmount() const {
    return amount;
}

const string& Transaction::GetCategory() const {
    return category;
}

time_t Transaction::GetTime() const {
    return transactionTime; 
}
