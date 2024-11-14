#include<iostream>
using namespace std;

class customer{
public:
string name;
int account_number;
int balance;
public:
 customer(string name,int account_number,int balance){
    this->name=name;
    this->account_number=account_number;
    this->balance=balance;
 }
 void display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Account Number: "<<account_number<<endl;
    cout<<"Balance: "<<balance<<endl;
 }
};

int main(){
    customer c1("John",12345,1000);
    c1.display();
}