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

const ll MAXN = 4e5;
ll n, x, y;
vec adj[MAXN];
ll ans = 0;

ll dfs(ll s, ll parent, ll now)
{
	ll current = 1;
	for(auto i : adj[s])
	{
		if(i != parent)
		{
			current += dfs(i, s, now);
		}
	}
	if(s == now)
	{
		ans = current;
	}
	return current;
}

int main()
{
	fastread;
	cin >> n >> x >> y;
	ll total = 1;
	rep(i,0,n-1)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ans = 0;
	dfs(x, 0, y);
	total *= ans;
	ans = 0;
	dfs(y, 0, x);
	total *= ans;
	total = (n * (n - 1)) - total;
	cout << total;
	return 0;
}