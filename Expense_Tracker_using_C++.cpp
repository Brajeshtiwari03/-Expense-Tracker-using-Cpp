#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

class Expense {
public:
    string category;
    string date;
    double amount;

    Expense(string c, string d, double a) {
        category = c;
        date = d;
        amount = a;
    }
};

vector<Expense> expenses;

void addExpense() {
    string category, date;
    double amount;

    cout << "Enter category: ";
    cin >> category;
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> date;
    cout << "Enter amount: ";
    cin >> amount;

    expenses.emplace_back(category, date, amount);
    cout << "Expense added!\n";
}

void viewExpenses() {
    cout << "\n--- All Expenses ---\n";
    cout << left << setw(15) << "Category" << setw(15) << "Date" << setw(10) << "Amount\n";
    cout << "----------------------------------------\n";
    for (auto &e : expenses) {
        cout << setw(15) << e.category << setw(15) << e.date << "$" << fixed << setprecision(2) << e.amount << endl;
    }
    cout << endl;
}

void totalExpenses() {
    double total = 0;
    for (auto &e : expenses) {
        total += e.amount;
    }
    cout << "Total Expenses: $" << fixed << setprecision(2) << total << endl;
}

void saveToFile() {
    ofstream file("expenses.txt");
    for (auto &e : expenses) {
        file << e.category << " " << e.date << " " << e.amount << endl;
    }
    file.close();
    cout << "Expenses saved to file.\n";
}

void loadFromFile() {
    ifstream file("expenses.txt");
    string category, date;
    double amount;
    expenses.clear();
    while (file >> category >> date >> amount) {
        expenses.emplace_back(category, date, amount);
    }
    file.close();
    cout << "Expenses loaded from file.\n";
}

int main() {
    int choice;
    loadFromFile();
    do {
        cout << "\nExpense Tracker Menu:\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. View Total\n";
        cout << "4. Save & Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: totalExpenses(); break;
            case 4: saveToFile(); cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
