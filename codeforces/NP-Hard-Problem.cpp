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
const ll maxn = 2e5;
vec *adj = new vec[maxn];
boolean visited(maxn, false);
ll n, m;
vec firstPart, secondPart;
vec color(maxn, 0);
bool possible = true;
void dfs(ll s, ll current)
{
	visited[s] = true;
	if(current == -1)
	{
		firstPart.pb(s);
		color[s] = -1;
	}
	else
	{
		secondPart.pb(s);
		color[s] = 1;
	}
	for(auto i : adj[s])
	{
		if(color[s] == color[i])
		{
			possible = false;
			return;
		}
		if(visited[i] == false)
		{
			dfs(i, current*(-1));
		}
	}
}
int main()
{
	fastread;
	cin>>n>>m;
	rep(i,0,m)
	{
		ll u, v;
		cin>>u>>v;
		--u;
		--v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep(i,0,n)
	{
		if(visited[i] == false)
		{
			dfs(i,-1);
		}
	}
	if(!possible)
	{
		cout<<-1;
		return 0;
	}
	ll size1 = 0, size2 = 0;
	for(auto i : firstPart)
	{
		if(adj[i].size() != 0)
		{
			++size1;
		}
	}
	for(auto i : secondPart)
	{
		if(adj[i].size() != 0)
		{
			++size2;
		}
	}
	if(possible)
	{
		cout<<size1<<'\n';
		for(auto i : firstPart)
		{
			if(adj[i].size() != 0)
				cout<<i+1<<" ";
		}
		cout<<'\n';
		
		cout<<size2<<'\n';
		for(auto i : secondPart)
		{
			if(adj[i].size() != 0)
				cout<<i+1<<" ";
		}
		
	}

	return 0;
}
