//template by chamow

#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
typedef long long ll;
ll d[30011],n,m;
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

void dfs(ll s, ll t)
{
	if(s<=0 || s>=m*2)
	{
		return;
	}
	if(d[s]<=t)
	{
		return;
	}
	d[s] = t;
	dfs(s*2, t+1);
	dfs(s-1, t+1);
}
int main()
{
	n = readInt();
	m = readInt();
	memset(d,1,sizeof(d));
	if(n>=m)
	{
		cout<<n-m;
	}
	else
	{
		dfs(n,0);
		cout<<d[m];	
	}		
    return 0;
}
