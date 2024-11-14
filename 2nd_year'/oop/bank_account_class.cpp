#include<iostream>
#include<string.h>

using namespace std;
class bank_account{
    private: 
    int account_number;
    string account_name;
    int balance;
    public:
    bank_account(int account_number,string account_name,int balance){
        this->account_number=account_number;
        this->account_name=account_name;
        this->balance=balance;
        }
        void deposit(int amount){
           
            balance+=amount;
            cout<<"Money deposited: "<<amount<<endl;
        }
        void withdraw(int amount){
            if(amount>balance){
                cout<<"Insufficient balance"<<endl;
            }
            else{
                balance-=amount;
                cout<<"Money withdrawed: "<<amount<<endl;
            }
        }
        void display_details(){
            cout<<"Account Number: "<<account_number<<endl;
            cout<<"Account Holder Name: "<<account_name<<endl;
            cout<<"Total Balance: "<<balance<<endl;
        }
};

int main(){
    bank_account bank_account(6577645,"kamal Hasan",1000);
    bank_account.display_details();
    bank_account.deposit(500);
    bank_account.display_details();
    bank_account.withdraw(269);
    bank_account.display_details();


    }