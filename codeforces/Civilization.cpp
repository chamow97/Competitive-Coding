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

const ll maxn = 4e5;
vec adj[maxn];
ll n, q, m;
ll maximum = -1, maxVertex = -1;
vec diameter(maxn, 0);
boolean visited(maxn, false);

struct subset{
	ll rank, parent;
};

vector<subset> S(maxn);

void initialize()
{
	rep(i,0,maxn)
	{
		S[i].parent = i;
		S[i].rank = 1;
	}
}

void dfs(ll curr, ll parent, ll depth)
{
	if(depth > maximum)
	{
		maximum = depth;
		maxVertex = curr;
	}
	for(auto i : adj[curr])
	{
		if(i != parent)
		{
			dfs(i, curr, depth + 1);
		}
	}
}

ll Find(ll x)
{
	if(S[x].parent == x)
	{
		return x;
	}
	return Find(S[x].parent);
}

void Union(ll x, ll y, ll type)
{
	x = Find(x);
	y = Find(y);
	if(x == y)
	{
		return;
	}
	if(S[x].rank < S[y].rank)
	{
		S[x].parent = y;
		S[y].rank += S[x].rank;
	}
	else 
	{
		S[y].parent = x;
		S[x].rank += S[y].rank;
	}
	if(type == 2)
	{
		if(S[x].rank > S[y].rank)
		{
			diameter[x] = max(diameter[x], max(diameter[y], (diameter[x] + 1)/2 + (diameter[y] + 1)/2 + 1));
		}
		else
		{
			diameter[y] = max(diameter[x], max(diameter[y], (diameter[x] + 1)/2 + (diameter[y] + 1)/2 + 1));
		}		
	}
}

ll findDiameter(ll currVertex)
{
	maximum = -1;
	dfs(currVertex, -1, 0);
	maximum = -1;
	dfs(maxVertex, -1, 0);
	return maximum;
}

int main()
{
	fastread;
	initialize();
	cin >> n >> m >> q;
	rep(i,0,m)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
		Union(u, v, 1);
	}
	rep(i,1,n+1)
	{
		ll currParent = Find(i);
		if(!visited[currParent])
		{
			visited[currParent] = true;
			diameter[currParent] = findDiameter(i);
		}
	}
	while(q--)
	{
		ll type, x, y;
		cin >> type;
		if(type == 1)
		{
			cin >> x;
			cout << diameter[Find(x)] << '\n';
		}
		else
		{
			cin >> x >> y;
			Union(x, y, 2);
		}
	}
	return 0;
}