#include<iostream>
#include<iomanip>

using namespace std;
int main()
{
float balance;
int cash;
cin>>cash;
cout<<" ";
cin>>balance;
cout<<std::fixed;
if(cash%5==0 && cash<=(balance-0.5))
{
    balance=(balance-cash-0.5);
    cout<<endl<<setprecision(2)<<balance;
}
else
    cout<<endl<<setprecision(2)<<balance;

}
