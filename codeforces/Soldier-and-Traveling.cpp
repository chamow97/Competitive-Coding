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

const ll MAXN = 150;
ll n, m;
ll adj[2 * MAXN + 1][2 * MAXN + 1];
ll maxFlow = 0;
vec parent(2 * MAXN + 1, -1);
boolean visited(2 * MAXN + 1, false);
ll sumA = 0;
ll sumB = 0;

bool bfs(ll s, ll v)
{
	queue<ll> q;
	q.push(s);
	visited[s] = true;
	while(!q.empty())
	{
		ll top = q.front();
		if(top == v)
		{
			return true;
		}
		q.pop();
		rep(i,0,2 * MAXN + 1)
		{
			if(adj[top][i] > 0 && visited[i] == false)
			{
				q.push(i);
				parent[i] = top;
				visited[i] = true;
			}
		}
	}
	return false;
}

void edmondKarp()
{
	while(bfs(0ll, 2 * MAXN))
	{
		ll pathFlow = INF;
		ll v = 2 * MAXN;
		while(v != 0)
		{
			ll prnt = parent[v];
			pathFlow = min(pathFlow, adj[prnt][v]);
			v = parent[v];
		}
		v = 2 * MAXN;
		while(v != 0)
		{
			ll prnt = parent[v];
			adj[prnt][v] -= pathFlow;
			adj[v][prnt] += pathFlow;
			v = parent[v];
		}
		maxFlow += pathFlow;
		fill(visited.begin(), visited.end(), false);
		fill(parent.begin(), parent.end(), -1);
	}
	if(maxFlow == sumB && maxFlow == sumA)
	{
		cout << "YES\n";
		rep(i,1,n+1)
		{
			rep(j,1,n+1)
			{
				cout << adj[j + MAXN][i] << ' ';
			}
			cout << '\n';
		}
	}
	else
	{
		cout << "NO";
	}
}

int main()
{
	fastread;
	cin >> n >> m;
	memset(adj, 0, sizeof(adj));
	rep(i,1,n+1)
	{
		ll val;
		cin >> val;
		adj[0][i] = val;
		sumA += val;
	}
	rep(i,1,n+1)
	{
		ll val;
		cin >> val;
		adj[i + MAXN][2 * MAXN] = val;
		sumB += val;
	}
	while(m--)
	{
		ll u, v;
		cin >> u >> v;
		adj[u][v + MAXN] = INF;
		adj[v][u + MAXN] = INF;
	}
	rep(i,1,n+1)
	{
		adj[i][MAXN + i] = INF;
	}
	edmondKarp();
	return 0;
}