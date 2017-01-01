#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,flag=0;
    cin>>n;
    while(n)
    {

        if(n%2!=0 && n>1)
        {
            flag=1;
            break;
        }
        else
        flag=0;
        n/=2;
    }
    if(flag==0)
        cout<<"TAK\n";
    else
        cout<<"NIE\n";
}
