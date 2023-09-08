#include <iostream>
#include "Card.h"
#include "Transaction.h"
#include "Wallet.h"
#include <limits>

using namespace std;

int main() {
    Wallet myWallet;
    Card c1("Даня", 1234567891011123, 30000, CardType::Debit, 0);
    Card c2("Сёма", 9876543219876543, 500000, CardType::Credit, 2000);
    
    myWallet.AddCard(c1);
    myWallet.AddCard(c2);
    
    int option = 0;
    
    while (true) {
        cout << "Меню:\n";
        cout << "1. Посмотреть карты\n";
        cout << "2. Добавить транзакцию\n";
        cout << "3. Депозитные баксы\n";
        cout << "4. Вывести баксы\n";
        cout << "5. Сохранить отчёт\n";
        cout << "6. Выйти\n";
        cout << "Выберите вариант: ";
        cin >> option;
        
        switch (option) {
            case 1:
                myWallet.PrintCards();
                break;
            case 2: {
                Card& selectedCard = myWallet.SelectCard();
                int amount;
                string category, comment;
                cout << "Введите сумму транзакции: ";
                cin >> amount;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Введите название категории: ";
                cin >> category;
                cout << "Введите комментарий: ";
                cin >> comment;
                Transaction t(amount, category, comment);
                selectedCard.AddTransaction(t);
                cout << "Транзакция добавлена.\n";
                break;
            }
            case 3: {
                Card& selectedCard = myWallet.SelectCard();
                int amount;
                cout << "Введите суму транзакции: ";
                cin >> amount;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                selectedCard.Deposit(amount);
                cout << "Внесённые баксы.\n";
                break;
            }
            case 4: {
                Card& selectedCard = myWallet.SelectCard();
                int amount;
                cout << "Введите сумму вывода: ";
                cin >> amount;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (selectedCard.Withdraw(amount)) {
                    cout << "Деньги выведены.\n";
                } else {
                    cout << "Недостаточно средств или превышен лимит.\n";
                }
                break;
            }
            case 5: {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка буфера ввода
                string filename;
                cout << "Введите имя файла отчёта: ";
                getline(cin, filename); // считывание имени файла
                myWallet.SaveReportToFile(filename); // вызов метода с именем файла
                cout << "Отчёт сохранён в " << filename << "\n";
                break;
            }
            case 6: {
                cout << "Выход...\n";
                return 0;
            }
            default:
                cout << "Операция не прошла.\n";
        }
    }
        
        return 0;
}

