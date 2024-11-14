#include<iostream>
using namespace std;
int main(){
    int x=3,y=8;
    cout<<x*y<<endl;
    x+=y;
    y+=x;
    cout<<x<<"\n"<<y;
}