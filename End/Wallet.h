#include <vector>
#include "Card.h"
using namespace std;

class Wallet {
private:
    vector<Card> cards;
public:
    void AddCard(const Card& card);
    Card& SelectCard();
    void ShowTopExpenses();
    void ShowTopCategories();
    void GenerateReport();
    void GenerateMonthlyReport();
    void SaveReportToFile(const string& filename);
    void PrintCards();
};
