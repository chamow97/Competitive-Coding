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

struct subset{
	ll rank, parent;
};

ll n;
const ll MAXN = 2e3 + 10;
ll arr[MAXN][MAXN];
vector< pair<ll, pair<ll, ll> > > adj;
vector< subset > sub(MAXN);
vecpair g[MAXN];

bool check()
{
	rep(i,1,n+1)
	{
		if(arr[i][i] != 0)
		{
			return false;
		}
	}
	rep(i,1,n+1)
	{
		rep(j,1,n+1)
		{
			if(arr[i][j] != arr[j][i])
			{
				return false;
			}
		}
	}
	return true;
}

bool myFunc(pair<ll, pair<ll, ll> > &a, pair<ll, pair<ll, ll> > &b)
{
	return a.s.s < b.s.s;
}

ll Find(ll s)
{
	if(sub[s].parent != s)
	{
		sub[s].parent = Find(sub[s].parent);
	}
	return sub[s].parent;
}

void Union(ll x, ll y)
{
	ll xParent = Find(x);
	ll yParent = Find(y);
	if(sub[xParent].rank < sub[yParent].rank)
	{
		sub[xParent].parent = yParent; 
	}
	else if(sub[yParent].rank < sub[xParent].rank)
	{
		sub[yParent].parent = xParent;
	}
	else
	{
		sub[xParent].parent = yParent;
		sub[yParent].rank++;
	}
}


bool dfs(ll s, ll p, ll ptr, ll dist)
{
	if(arr[ptr][s] != dist)
	{
		return false;
	}
	for(auto i : g[s])
	{
		if(i.f == p)
		{
			continue;
		}
		if(!dfs(i.f, s, ptr, dist + i.s))
		{
			return false;
		}
	}
	return true;
}

void kruskal()
{
	sort(adj.begin(), adj.end(), myFunc);
	rep(i,0,n+1)
	{
		sub[i].rank = 0;
		sub[i].parent = i;
	}
	rep(i,0,adj.size())
	{
		ll u = adj[i].f;
		ll v = adj[i].s.f;
		ll w = adj[i].s.s;
		if(w == 0)
		{
			cout << "NO";
			return;
		}
		if(Find(u) != Find(v))
		{
			g[u].pb(mp(v, w));
			g[v].pb(mp(u, w));
			Union(u, v);
		}
	}
	rep(i,1,n+1)
	{
		if(!dfs(i, -1, i, 0))
		{
			cout << "NO";
			return;
		}
	}
	cout << "YES";
}


int main()
{
	fastread;
	cin >> n;
	memset(arr, 0, sizeof(arr));
	rep(i,1,n+1)
	{
		rep(j,1,n+1)
		{
			cin >> arr[i][j];
		}
	}
	// if(check())
	// {
	rep(i,1,n+1)
	{
		rep(j,i + 1, n + 1)
		{
			adj.pb(mp(i, mp(j, arr[i][j])));
		}	
	}
	kruskal();

	// }
	// else
	// {
	// 	cout << "NO";
	// }
	return 0;

}