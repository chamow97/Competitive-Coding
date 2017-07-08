#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val) for(int j=val-1;j>=0;j--)
#define pb push_back
typedef long long ll;
int main()
{
    ll n,x[100000],h[100000],i,j,counter=0;
    cin>>n;
    rep(i,0,n)
    {
        cin>>x[i]>>h[i];
    }
    if(n==1)
    {
        cout<<"1";
    }
    else if(n==2)
    {
        cout<<"2";
    }
    else
    {
        rep(i,1,n-1)
    {
        if(x[i]-x[i-1]>h[i])
        {
            ++counter;
        }
        else if(x[i+1]-x[i]>h[i])
        {
            ++counter;
            x[i]+=h[i];
        }
    }
    cout<<counter+2;

    }


    return 0;
}
