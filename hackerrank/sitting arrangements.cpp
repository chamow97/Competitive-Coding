//template by chamow
//template
#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
typedef long long ll;
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
ll solve(ll n, ll m)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    if(n%2 == 0 && m%2 == 0)
    {
        return solve(n/2, m/2);
    }
    else if(n%2 == 1 && m%2 == 0)
    {
        return m + solve(n/2, m/2);
    }
    else if(n%2 == 0 && m%2 == 1)
    {
        return n + solve(n/2, m/2);
    }
    else
    {
        return n + m -1 + solve(n/2, m/2);
    }
}
int main()
{
    ll t,n,m;
    t = readInt();
    while(t--)
    {
        ll answer = 0;
        n = readInt();
        m = readInt();
        cout<<solve(n,m)<<endl;
    }
    return 0;
}

