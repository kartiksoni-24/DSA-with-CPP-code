// Problem:
// Manage a bank account's balance after deposits and withdrawals.
//
// Approach:
// Keep the account details inside a class and update the balance through member functions.
//
// Complexity:
// Time: O(1)
// Space: O(1)
#include<iostream>
using namespace std;

class BankAcc{
    int accNo;
    float balance;

public:
    BankAcc(int accNo, float balance){
        this->accNo = accNo;
        this->balance = balance;
    }

    float deposite(float amount){
       return this->balance += amount;
    }

    float withdraw(float amount){
        return this->balance -= amount;
    } 

    void getBalance(){
        cout << "$" <<this->balance << " is the current balance of " << this->accNo << endl;
    }
};

int main(){
    BankAcc u1(101, 2043.56);
    BankAcc u2(106, 203.6);

    u1.deposite(5000.25);
    u1.withdraw(2444.4);

    u1.getBalance();
    u2.getBalance();


    return 0;
}
