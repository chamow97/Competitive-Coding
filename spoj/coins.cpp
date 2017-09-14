#include<bits/stdc++.h>
using namespace std;

int main()
{
    long sum=0,n,t=10;

    while(t--)
    {
        sum=0;
        cin>>n;
        sum=(n/2)+(n/3)+(n/4);
        cout<<max(sum,n)<<'\n';
    }
}
