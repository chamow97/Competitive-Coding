#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==0 || n%6 == 0)
        {
            cout<<"Misha\n";
        }
        else
        {
            cout<<"Chef\n";
        }
    }
}
