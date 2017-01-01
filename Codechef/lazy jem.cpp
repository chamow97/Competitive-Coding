#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,t,b,m,total=0,value;
    cin>>t;
    while(t--)
    {
        total=0;
        cin>>n>>b>>m;
        while(n)
        {
            value=(n+1)/2;
            n=n-((n+1)/2);
            total=total+((value)*m);
            m*=2;
            total=total+b;

        }
        cout<<total-b<<'\n';
    }
}
