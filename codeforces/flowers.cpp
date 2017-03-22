//template by chamow

#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define n 100001
typedef long long ll;
ll MODULO = 1000000007;

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
    ll t,k,a,b;
    t = readInt();
    k = readInt();
    vector<ll> dp(100001);
    vector<ll> s(100001);
    s[0] = 0;
    dp[0] = 1;
    rep(i,1,n)
    {
        if(i < k)
        {
            dp[i] = dp[i-1];
        }
        else
        {
            dp[i] = (dp[i-1] + dp[i-k]);
        }
        if(dp[i] >= MODULO)
        {
            dp[i] -= MODULO;
        }
    }
    rep(i,1,n)
    {
        s[i] = s[i-1] + dp[i];
        if(s[i] >= MODULO)
        {
            s[i] -= MODULO;
        }
    }
    while(t--)
    {
        a = readInt();
        b = readInt();
        cout<<(s[b] - s[a-1] + MODULO)%(MODULO)<<endl;
    }
    return 0;
}
