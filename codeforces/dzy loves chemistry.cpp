//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157

/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;

/*-------------------------------------------------------- */
ll counter = 0;
boolean visited(2500, false);
	
void dfs(ll s, vector<ll> *adj)
{
	visited[s] = true;
	vector<ll>::iterator i;
	for(i = adj[s].begin(); i != adj[s].end(); i++)
	{
		if(visited[*i] == false)
		{
			dfs(*i, adj);
		}
	}
}

int main()
{
	ll n,m, maximum = 0, u, v;
	cin>>n>>m;
	vector<ll> *adj = new vector<ll>[n];
	rep(i,0,m)
	{
		cin>>u>>v;
		u -= 1;
		v -= 1;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep(i,0,n)
	{
		if(visited[i] == false)
		{
			++counter;
			dfs(i,adj);
		}
	}
	ll ans = pow(2,n-counter);
	cout<<ans;
	return 0;
}