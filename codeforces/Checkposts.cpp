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
vec *adj = new vec[maxn];
vec *revAdj = new vec[maxn];
vector<vec> scc;
ll n, m;
vec cost(maxn, 0);
boolean visited(maxn, false);
stack<ll> st;
vec now;
void reverseDFS(ll s)
{
	visited[s] = true;
	now.pb(s);
	for(auto i : revAdj[s])
	{
		if(!visited[i])
		{
			reverseDFS(i);
		}
	}
}
void forwardDFS(ll s)
{
	visited[s] = true;
	for(auto i : adj[s])
	{
		if(!visited[i])
		{
			forwardDFS(i);
		}
	}
	st.push(s);
}

void kosaraju()
{
	rep(i,1,n+1)
	{
		if(!visited[i])
		{
			forwardDFS(i);
		}
	}
	fill(visited.begin(), visited.end(), false);	
	while(!st.empty())
	{
		ll front = st.top();
		st.pop();
		now.resize(0);
		if(!visited[front])
		{
			reverseDFS(front);
			scc.pb(now);
		}
	}
	ll ways = 1;
	ll minCost = 0;
	rep(i,0,scc.size())
	{
		ll minimum = INF;
		ll counter = 0;
		for(auto u : scc[i])
		{
			minimum = min(minimum, cost[u]);
		}
		for(auto u : scc[i])
		{
			if(cost[u] == minimum)
			{
				++counter;
			}
		}
		minCost += minimum;
		ways *= (counter);
		ways %= MODULO;
	}
	cout << minCost << ' ' << ways;
}

int main()
{
	fastread;
	cin >> n;
	rep(i,1,n+1)
	{
		cin >> cost[i];
	}
	cin >> m;
	rep(i,0,m)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		revAdj[v].pb(u);
	}
	kosaraju();
	return 0;
}