#include <iostream>
#include <limits>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;
class Account
{
private:
    string accountNumber;
    string accountType;
    double balance;

public:
    Account(string number, string type, double init) : accountNumber(number), accountType(type), balance(init) {}

    string getacc() const
    {
        return accountNumber;
    }
    string gettype() const
    {
        return accountType;
    }
    double getbalance() const
    {
        return balance;
    }

    void display()
    {
        cout << "Account #: " << accountNumber
             << " | Type: " << accountType
             << " | Balance: $" << fixed << setprecision(2) << balance << "\n";
    }
};
class user
{
private:
    string username;
    int pin;
    vector<Account> accounts;

public:
    user(  const string& uname, const int &pass) : username(uname), pin(pass) {}
    string getname() const
    {
        return username;
    }
    bool check(int epin)
    {
        return pin == epin;
    }
    void addacc(Account &acoount)

    {
        accounts.push_back(acoount);
    }
    void displayAccounts() const
    {
        if (accounts.empty())
        {
            cout << "No accounts found.\n";
            return;
        }

        cout << "\n----- Your Accounts -----\n";
        for ( auto a : accounts)
        {
            a.display();
        }
        cout << "--------------------------\n";
    }
};
vector<user> users;
int nextAccountNumber = 3000;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void creatnewuser(){
    string uname;
    int pin;
    cout << "\n===== Create New Account =====\n";
    cout << "Enter new username: ";
    cin >> uname;
    // Check duplicate
    for (auto& u : users) {
        if (u.getname() == uname) {
            cout << "Username already exists. Try again.\n";
            return;
        }
    }

    cout << "Enter 4-digit PIN: ";
    cin >> pin;

    user newUser(uname, pin);

    // Auto create default Checking account
    Account acc(to_string(nextAccountNumber++), "Checking", 0.00);
    newUser.addacc(acc);

    users.push_back(newUser);

    cout << "\nAccount created successfully. You can now log in.\n";
}
    

user* login() {
    string uname;
    int  pin;

    cout << "\n===== Login =====\n";
    cout << "Username: ";
    cin >> uname;

    cout << "PIN: ";
    cin >> pin;

    for (auto& u : users) {
        if (u.getname() == uname && u.check(pin)) {
            cout << "Login successful!\n";
            return &u;
        }
    }

    cout << "Invalid login.\n";
    return nullptr;
}
void userHome(user* user) {
    int choice;

    do {
        cout << "\n===== Dashboard =====\n";
        cout << "1. View My Accounts\n";
        cout << "2. Logout\n";
        cout << "Enter option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            user->displayAccounts();
            break;
        case 2:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid option!\n";
        }

    } while (choice != 2);
}



int main()
{int choice;

    do {
        cout << "\n==============================\n";
        cout << "      Welcome to MyBank       \n";
        cout << "==============================\n";
        cout << "1. Login\n";
        cout << "2. Create New Account\n";
        cout << "3. Exit\n";
        cout << "Select option: ";
        cin >> choice;

        if (cin.fail()) {
            clearInput();
            cout << "Invalid input.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            user* user = login();
            if (user != nullptr)
                userHome(user);
            break;
        }
        case 2:
            creatnewuser();
            break;
        case 3:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 3);

   
    return 0;
}