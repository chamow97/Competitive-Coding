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
const ll maxn = 1e6;
vec gold(maxn, 0);
vec *adj = new vec[maxn];
boolean visited(maxn, false);
ll minimum = INF;

void dfs(ll s, ll &minimum)
{
	visited[s] = true;
	minimum = min(minimum, gold[s]);
	for(auto i : adj[s])
	{
		if(visited[i] == false)
		{
			dfs(i, minimum);
		}
	}
}

int main()
{
	fastread;
	ll n, m;
	cin >> n >> m;
	rep(i,0,n)
	{
		cin >> gold[i];
	}
	rep(i, 0, m)
	{
		ll u, v;
		cin >> u >> v;
		--u;
		--v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ll ans = 0;
	rep(i,0,n)
	{
		if(visited[i] == false)
		{
			minimum = INF;
			dfs(i, minimum);
			ans += minimum;
		}
	}
	cout << ans;
	return 0;
}
 	