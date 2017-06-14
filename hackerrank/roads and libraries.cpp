//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;


/*-------------------------------------------------------- */

ll gcd(ll a, ll b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a,b));
}

/*-------------------------------------------------------- */
void dfs(vec *adj, boolean &visited, ll s, ll &counter)
{
	visited[s] = true;
	vec::iterator it;
	for(it = adj[s].begin(); it != adj[s].end(); it++)
	{
		if(visited[*it] == false)
		{
			counter++;
			dfs(adj, visited, *it, counter);
		}
	}
}

int main()
{
	fastread;
	ll q;
	cin>>q;
	while(q--)
	{
		ll n, m, clib, croad;
		cin>>n>>m>>clib>>croad;
		vec *adj = new vec[n];
		ll u, v;
		rep(i,0,m)
		{
			cin>>u>>v;
			--u;
			--v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		ll counter = 0, connectedComponent = 0, value = 0;
		boolean visited(n,false);
		rep(i,0,n)
		{
			if(visited[i] == false)
			{
				counter = 1;
				dfs(adj, visited, i, counter);
				connectedComponent += counter;
				value += ((counter-1)*croad);
				value += clib;
			}
		}
		// value += ((n-connectedComponent)*clib);
		cout<<min(value, (n)*clib)<<'\n';
	}
	return 0;
}