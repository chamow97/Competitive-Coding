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
ll n, m;
const ll maxn = 1e6+100;
ll color[maxn];
set<ll> adj[maxn];
boolean isAvailable(maxn, false);
int main()
{
	fastread;
	cin >> n >> m;
	ll maximum = 0;
	ll col = INF;
	rep(i,1,n+1)
	{
		cin >> color[i];
		col = min(col, color[i]);
	}
	rep(i,1,m+1)
	{
		ll u, v;
		cin >> u >> v;
		if(color[u] == color[v])
		{
			continue;
		}
		adj[color[u]].insert(color[v]);
		adj[color[v]].insert(color[u]);
	}
	rep(i,1,maxn)
	{
		if(adj[i].size() > maximum)
		{
			maximum = adj[i].size();
			col = i;
		}			
	}
	cout << col;
	
	return 0;
}