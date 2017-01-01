#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val) for(int j=val-1;j>=0;j--)
#define pb push_back
#define mnm minimum
#define mx maximum
typedef long long ll;
int main()
{
    ll a,b,mnm,mx,counter=0;
    cin>>a>>b;
    while(1)
    {
        mnm=min(a,b);
        mx=max(a,b);
        a=mnm;
        b=mx;
        if(b-2<0)
            break;
        if(a-1<0)
            break;
        b-=2;
        a-=1;
        ++counter;

    }
    cout<<counter;
    return 0;
}
