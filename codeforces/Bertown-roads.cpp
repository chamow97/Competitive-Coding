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
ll n, m;
vec *adj = new vec[maxn];
boolean visited(maxn);
vec parent(maxn, -1);
vec vertices;
ll sizes = 0;

void forwardDFS(ll s)
{
	visited[s] = true;
	for(auto i : adj[s])
	{
		if(!visited[i])
		{
			parent[i] = s;
			forwardDFS(i);

		}
	}
	vertices.pb(s);
}

void reverseDFS(ll s)
{
	visited[s] = true;
	for(auto i : adj[s])
	{
		if(!visited[i] && parent[i] != s)
		{
			reverseDFS(i);
		}
	}
}

map<pair<ll, ll>, ll> m1;
ll counter[maxn];

void constrainedDFS(ll s)
{
	if(sizes > m)
	{
		return;
	}
	while(counter[s]<adj[s].size())
	{
		ll i = adj[s][counter[s]];
		++counter[s];
		if(m1[mp(min(s, i), max(s, i))] != 1)
		{
			cout << s << ' ' << i << '\n';
			++sizes;
			m1[mp(min(s, i), max(s, i))] = 1;
			constrainedDFS(i);
		}
	}
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
		if(!visited[i])
		{
			forwardDFS(i);
		}
	}
	fill(visited.begin(), visited.end(), false);
	per(j,vertices.size()-1, 0)
	{
		ll now = vertices[j];
		if(!visited[now])
		{
			reverseDFS(now);
			++sizes;
		}
	}
	if(sizes != 1)
	{
		cout << 0;
	}
	else
	{
		sizes = 0;
		constrainedDFS(1);
	}
	return 0;
}