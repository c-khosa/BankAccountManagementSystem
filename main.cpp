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
    user(const string &uname, const int &pass) : username(uname), pin(pass) {}
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


int main()
{
    return 0;
}