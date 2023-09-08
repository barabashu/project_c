#ifndef WALLET_H
#define WALLET_H

#include <vector>
#include "Card.h"

using namespace std;

class Wallet {
private:
    vector<Card> cards;
public:
    void AddCard(const Card& card);
    void PrintCards();
    Card& SelectCard();
};

#endif // WALLET_H
