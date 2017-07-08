//template by chamow

#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
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
	ll dp[100001],temp,n,count[100001];
	n = readInt();
	rep(i,0,100001)
	{
		count[i] = 0;
	}
	rep(i,1,n+1)
	{
		temp = readInt();
		count[temp]++;
	}
	count[0] = 0;
	dp[0] = 0;
	dp[1] = count[1];
	rep(i,2,100001)
	{
		dp[i] = max(dp[i-1], i*count[i] + dp[i-2]);
	}
	cout<<dp[100000];
    return 0;
}
