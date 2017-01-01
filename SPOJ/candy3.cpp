#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long i,t,n,sum=0,a;
    cin>>t;
    while(t--)
    {
        sum=0;
        cout<<'\n';
        cin>>n;
        if(n==0)
            continue;
        for(i=0;i<n;i++)
        {
            cin>>a;
            sum+=a;
            sum=sum%n;
        }
        if(sum%n==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }
}
