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

ll t;
ll n, m;
const ll maxn = 1e4;
vec *adj = new vec[maxn];
boolean visited(maxn, false);
ll maximum = 0;
vec parent(maxn, 0);
vec counter(maxn, 0);

void clearAll()
{
	rep(i,0,maxn)
	{
		adj[i].resize(0);
	}
	fill(visited.begin(), visited.end(), false);
	fill(parent.begin(), parent.end(), 0);
	fill(counter.begin(), counter.end(), 0);
	maximum = 0;
}

void dfs(ll s, ll now)
{
	if(counter[s] == 2)
	{
		return;
	}
	if(counter[s] == 1)
	{
		maximum = max(maximum, parent[now] - parent[s] + 1);
		return;
	}
	counter[s] = 1;
	if(now == -1)
	{
		parent[s] = 0;
	}
	else
	{
		parent[s] = parent[now] + 1;
	}
	for(auto i : adj[s])
	{
		if(i != now)
		{
			dfs(i, s);
		}
	}
	counter[s] = 2;
}

int main()
{
	assert(freopen("d.in","r",stdin));
    assert(freopen("d.out","w",stdout));
	cin >> t;
	while(t--)
	{
		clearAll();
		cin >> n >> m;
		rep(i,0,m)
		{
			ll u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		rep(i,1,n+1)
		{
			if(!visited[i])
			{
				dfs(i, -1);
			}
		}
		cout << maximum << '\n';
	}
	return 0;
}