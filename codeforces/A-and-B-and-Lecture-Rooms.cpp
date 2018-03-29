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

const ll maxn = 1e5 + 100;
vec *adj = new vec[maxn];
vec depth(maxn, 0);
vec sum(maxn, 1);
const ll logN = 22;
ll parentArr[maxn][logN];
ll n, m;

ll findKthAncestor(ll a, ll k)
{
	per(j,logN,0)
	{
		if((1 << j) <= k)
		{
			k -= (1 << j);
			a = parentArr[a][j];
		}
	}
	return a;
}

void dfs(ll node, ll parent)
{
	for(int i : adj[node])
	{
		if(i == parent)
		{
			continue;
		}
		depth[i] = depth[node] + 1;
		parentArr[i][0] = node;
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
			parentArr[i][j] = parentArr[parentArr[i][j-1]][j-1];
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
			u = parentArr[u][j];
		}
	}

	if(u == v)
	{
		return u;
	}

	per(j,logN-1,0)
	{
		if(parentArr[u][j] == 0 || parentArr[v][j] == 0 || parentArr[u][j] == parentArr[v][j])
		{
			continue;
		}
		u = parentArr[u][j];
		v = parentArr[v][j];
	}
	return parentArr[u][0];
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
	}
	cin >> m;
	dfs(1, 0);
	preprocess();
	while(m--)
	{
		ll u, v;
		cin >> u >> v;
		ll ans = 0;
		ll lca = LCA(u, v);
		ll curr = depth[v] + depth[u] - 2 * depth[lca];
		
		if(depth[u] < depth[v])
		{
			swap(u, v);
		}
		if(curr % 2 == 0)
		{
			if(u == v)
			{
				ans = n;
			}
			else if(depth[u] == depth[v])
			{
				ans = n - sum[findKthAncestor(u, depth[u] - depth[lca] - 1)] - sum[findKthAncestor(v, depth[v] - depth[lca] - 1)];
			}		
			else
			{
				ll midDepth = (curr/2);
				ll midNode = findKthAncestor(u, midDepth);
				ll midNode1 = findKthAncestor(u, midDepth - 1);
				// cout << midNode << ' ' << u;
				ans = sum[midNode] - sum[midNode1];
			}
			cout << ans;
		}
		else
		{
			cout << 0;
		}
		cout << '\n';
	}
	return 0;
}