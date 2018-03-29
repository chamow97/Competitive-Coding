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
ll n, m;
vec *adj = new vec[maxn];
bool flag = false;
ll ans = 0;
vec visited(maxn, 0);

void dfs(ll s, ll parent)
{
	visited[s] = 1;
	for(auto i : adj[s])
	{
		if(i != parent)
		{
			if(visited[i] == 0)
			{
				dfs(i, s);
			}
			if(visited[i] == 1)
			{
				flag = true;
				return;
			}
		}
	}
	visited[s] = 2;
}

int main()
{
	fastread;
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
		if(visited[i] == 0)
		{
			flag = false;
			dfs(i, -1);
			if(!flag)
			{
				++ans;
			}
		}
	}
	cout << ans;
	return 0;
}