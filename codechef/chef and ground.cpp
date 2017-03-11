#include<bits/stdc++.h>

using namespace std;

int main()
{
    long i,sum=0,t,n,m,a[100];
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n>>m;
        for(i=0;i<n;i++)
            {
                cin>>a[i];
                sum+=a[i];
            }
            sum+=m;
            if(sum%n==0)
                cout<<"Yes\n";
            else
                cout<<"No\n";
    }
}
