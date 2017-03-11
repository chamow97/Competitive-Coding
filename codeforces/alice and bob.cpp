//template by chamow

#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
typedef long long ll;
ll gcd(ll a,ll b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}
ll readInt () {
	bool minus = false;
	ll result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
int main()
{
    ll n,a[100],counter=0,maxi=-10000000,g=0;
    n=readInt();
    rep(i,0,n)
    {
        a[i]=readInt();
    }
    //cout<<gcd(20,5)<<gcd(5,20);
    rep(i,0,n)
    {
        g=gcd(g,a[i]);
        maxi=max(maxi,a[i]);
    }
    maxi=(maxi/g)-n;
    if(maxi&1)
    {
        cout<<"Alice";
    }
    else
    {
        cout<<"Bob";
    }
    return 0;
}
