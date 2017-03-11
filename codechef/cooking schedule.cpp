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
	ll t,n,k,maxdiff=0,diff2,diff1,diff;
	string s;
	t = readInt();
	while(t--)
	{
		maxdiff = 0;
		diff1=0;
		diff2=0;
		n = readInt();
		k = readInt();
		vector<ll> dp(n);
		priority_queue<ll> pq;
		cin>>s;
		rep(i,0,n)
		{
			if(i & 1 == 1)
			{
				if(s[i] == '0')
				{
					++diff2;
				}
				else
				{
					++diff1;
				}
			}
			else
			{
				if(s[i] == '0')
				{
					++diff1;
				}
				else
				{
					++diff2;
				}
			}
		}
		diff = min(diff1,diff2);
		dp[0] = 1;
		rep(i,1,n)
		{
			if(s[i] == s[i-1])
			{
				dp[i] = 1 + dp[i-1];
			}
			else
			{
				dp[i] = 1;
			}
			maxdiff = max(maxdiff,dp[i]);
		}
		if(diff <= k)
		{
			cout<<"1"<<endl;
		}
		else if(maxdiff == 1)
		{
			cout<<"1"<<endl;
		}
		else if(maxdiff == 2)
		{
			cout<<"2"<<endl;
		}
		
		

	}

	return 0;
}