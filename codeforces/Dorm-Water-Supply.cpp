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

const ll maxn = 1e4 + 100;
vecpair *adj = new vecpair[maxn];
map<ll, ll> incoming;
map<ll, ll> outgoing;
ll sum = INF;
boolean visited(maxn, false);

ll dfs(ll st)
{
	visited[st] = true;
	for(auto i : adj[st])
	{
		ll v = i.f;
		ll w = i.s;
		if(!visited[v])
		{
			sum = min(sum, w);
			return dfs(v);
		}
	}
	return st;
}

int main()
{
	fastread;
	ll n, p;
	vector< pair<ll, pair<ll, ll> > > ans;
	cin >> n >> p;
	rep(i,0,p)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].pb(mp(v, w));
		outgoing[u]++;
		incoming[v]++;
	}
	rep(i,1,n+1)
	{
		if(incoming[i] == 0)
		{
			sum = INF;
			ll destination = dfs(i);
			if(sum != INF)
			ans.pb(mp(i, mp(destination, sum)));
		}
	}
	cout << ans.size() << '\n';
	for(auto i : ans)
	{
		cout << i.f << ' ' << i.s.f << ' ' << i.s.s << '\n';
	}
	return 0;
}