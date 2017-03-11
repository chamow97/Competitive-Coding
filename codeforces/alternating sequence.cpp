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
int main()
{
	ll n,maximum = 0,temp[2];
	string s;
	n = readInt();
	ll dp[n+1];
	cin>>s;
	dp[0] = 0;
	dp[1] = 1;
	rep(i,1,n)
	{
		if(s[i] != s[i-1])
		{
			dp[i+1] = 1+dp[i];
		}
		else
		{
			dp[i+1] = dp[i];
		}
	}
	rep(i,1,n+1)
	{
		maximum = max(maximum, dp[i]);
	}
	if(temp[0] == temp[1])
	{
		maximum = n;
	}
	cout<<min(n, maximum + 2);

    return 0;
}
