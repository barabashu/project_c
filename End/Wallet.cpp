#include "Wallet.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void Wallet::AddCard(const Card& card) {
    cards.push_back(card);
}

void Wallet::PrintCards() {
    cout << "Доступные карты:" << endl;
    for(int i = 0; i < cards.size(); ++i) {
        cout << "[" << i + 1 << "] ";
        cards[i].PrintCard();
    }
}

Card& Wallet::SelectCard() {
    int choice;
    PrintCards();
    cout << "Выберите карту по ее номеру: ";
    cin >> choice;
    return cards[choice - 1];
}

void Wallet::GenerateReport() {
    cout << "Генерация отчёта...\n";
    for (const auto& card : cards) {
        cout << "Отчёт по карте: " << card.GetName() << endl;
        card.PrintTransactions();
    }
}

void Wallet::GenerateMonthlyReport() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    ltm->tm_mday = 1;
    time_t startOfMonth = mktime(ltm);
    ltm->tm_mon += 1;
    time_t startOfNextMonth = mktime(ltm);
    
    for (const auto& card : cards) {
        vector<Transaction> monthlyTransactions = card.GetTransactionsInDateRange(startOfMonth, startOfNextMonth);
    }
}

void Wallet::ShowTopExpenses() {
    cout << "Топ-3 затрат:\n";
    vector<Transaction> allTransactions;
    for (const auto& card : cards) {
        vector<Transaction> cardTransactions = card.GetTransactions();
        allTransactions.insert(allTransactions.end(), cardTransactions.begin(), cardTransactions.end());
    }
    sort(allTransactions.begin(), allTransactions.end(), [](const Transaction& a, const Transaction& b) {
        return a.GetAmount() > b.GetAmount();
    });
    for (int i = 0; i < min(3, (int)allTransactions.size()); ++i) {
        cout << allTransactions[i].GetAmount() << " " << allTransactions[i].GetCategory() << endl;
    }
}

void Wallet::SaveReportToFile(const string& filename) {
    ofstream file(filename);
    if(!file) {
        cerr << "Не удалось открыть файл для сохранения отчета.\n";
        return;
    }
    file << "Отчёт:\n";
    for (const auto& card : cards) {
        file << "Карта: " << card.GetName() << "\n";
        for (const auto& transaction : card.GetTransactions()) {
            file << transaction.GetAmount() << " " << transaction.GetCategory() << "\n";
        }
    }
    file.close();
    cout << "Отчёт сохранён в " << filename << "\n";
}

