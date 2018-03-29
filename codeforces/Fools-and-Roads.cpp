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
#define vecit vector<ll> :: iterator
#define vecpit vector< pair<ll, ll> > :: iterator
#define f first
#define s second


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;
typedef vector< pair<ll, ll> > vecpair;


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
const ll maxn = 1e5+100;
ll n;
vec *adj = new vec[maxn];
vec sum(maxn, 0);
vec depth(maxn, 0);
const ll logN = 24;
ll parent[maxn][logN];
ll x[maxn];
ll y[maxn];

void dfs(ll node, ll prnt)
{
	for(int i : adj[node])
	{
		if(i == prnt)
		{
			continue;
		}
		depth[i] = depth[node] + 1;
		parent[i][0] = node;
		dfs(i, node);
		sum[node] += sum[i];
	}
}

void preprocess()
{
	rep(j,1,logN)
	{
		rep(i,1,n+1)
		{
			parent[i][j] = parent[parent[i][j-1]][j-1];
		}
	}
}

ll LCA(ll u, ll v)
{
	// if u is at a higher height
	if(depth[u] < depth[v])
	{
		swap(u, v);
	}

	per(j,logN-1,0)
	{
		ll currVal = 1 << j;
		if(depth[u] - currVal >= depth[v])
		{
			u = parent[u][j];
		}
	}

	if(u == v)
	{
		return u;
	}

	per(j,logN-1,0)
	{
		if(parent[u][j] == 0 || parent[v][j] == 0 || parent[u][j] == parent[v][j])
		{
			continue;
		}
		u = parent[u][j];
		v = parent[v][j];
	}
	return parent[u][0];
}	

int main()
{
	fastread;
	cin >> n;
	rep(i,1,n)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
		x[i] = u;
		y[i] = v;
	}
	ll k;
	cin >> k;
	dfs(1, 1);
	preprocess();
	while(k--)
	{
		ll u, v;
		cin >> u >> v;
		sum[u]++;
		sum[v]++;
		sum[LCA(u, v)] -= 2;
	}
	dfs(1, 1);
	rep(i,1,n)
	{
		if(depth[x[i]] < depth[y[i]])
		{
			swap(x[i], y[i]);
		}

		cout << sum[x[i]] << ' ';
	}
	return 0;
}