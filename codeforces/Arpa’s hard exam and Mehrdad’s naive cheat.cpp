#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,t;

    cin>>n;
    t=n;
    n=n%4;
    if(n==0 && t==0)
    {
        cout<<"1";
    }
    else if(n==0)
    {
        cout<<"6";
    }
    else if(n==1)
    {
        cout<<"8";
    }
    else if(n==2)
    {
        cout<<"4";
    }
    else
    {
        cout<<"2";

    }
}
