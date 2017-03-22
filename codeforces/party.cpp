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
ll counter = 0;
ll dfs(ll s, vector<ll> *adj, vector<bool> visited)
{
	visited[s] = true;
	++counter;
	vector<ll>::iterator it;
	for(it = adj[s].begin(); it != adj[s].end(); it++)
	{
		if(!visited[*it])
		{
			dfs(*it, adj, visited);
		}
	}
	return counter;
}
int main()
{
	ll n, v, maximum = 0;
	n = readInt();
	vector<ll> *adj = new vector<ll>[n+1];
    rep(i,0,n)
    {
    	v = readInt();
    	if(v != -1)
    	{
    		adj[i+1].pb(v);
    	}
    	
    }
    rep(i,0,n)
    {
    	counter = 0;
    	vector<bool> visited(n+1, false);
    	maximum = max(maximum, dfs(i+1, adj, visited));
    }
    cout<<maximum;
    return 0;
}
