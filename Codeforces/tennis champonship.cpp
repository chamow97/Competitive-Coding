#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
typedef long long ll;
int main()
{
    ll n,a=1,b=2,c,sum=0;
    cin>>n;
    while(b<=n)
    {
        sum++;
        c=a+b;
        a=b;
        b=c;
        //cout<<b<<endl;
    }
    cout<<sum;
    return 0;
}
