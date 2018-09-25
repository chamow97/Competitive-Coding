//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vecit vector<int> :: iterator
#define vecpit vector< pair<int, int> > :: iterator
#define f first
#define s second


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<int> vec;
typedef vector< pair<int, int> > vecpair;


/*-------------------------------------------------------- */
ll n, m;

const ll MAXN = 600;
vec adj[MAXN];
vec color(MAXN, 0);
bool isCycle = false;
stack<ll> cycleNodes;

bool isCyclic(ll s)
{
	color[s] = 1;
	cycleNodes.push(s);
	for(auto i : adj[s])
	{
		if(i == -1)
		{
			continue;
		}
		if(color[i] == 1)
		{
			cycleNodes.push(i);
			return true;
		}
		if(color[i] == 0 && isCyclic(i))
		{
			return true;
		}
	}
	color[s] = 2;
	return false;
}

int main()
{
	/*
	Logic - Naive logic fails as m*(n+m) is too much
	Rather find a cycle and remove edges between them if its there and see cycles
	Since only N nodes can be in a cycle at max, n*n*(n+m) passes
	*/
	cin >> n >> m;
	rep(i,0,m)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}
	rep(i,1,n+1)
	{
		if(color[i] == 0)
		{
			if(isCyclic(i))
			{
				isCycle = true;
				break;
			}
		}
	}
	rep(i,1,n+1)
	{
		sort(adj[i].begin(), adj[i].end());
	}
	if(!isCycle)
	{
		cout << "YES";
		return 0;
	}
	else
	{
		vec cycle;
		ll start = cycleNodes.top();
		cycle.pb(start);
		cycleNodes.pop();
		while(!cycleNodes.empty() && cycleNodes.top() != start)
		{
			cycle.pb(cycleNodes.top());
			cycleNodes.pop();
		}
		rep(i,0,cycle.size())
		{
			rep(j,0,cycle.size())
			{
				if(i == j)
				{
					continue;
				}
				isCycle = false;
				ll u = cycle[i];
				ll v = cycle[j];
				ll pos = lower_bound(adj[u].begin(), adj[u].end(), v) - adj[u].begin();
				if(pos == adj[u].size())
				{
					continue;
				}
				if(adj[u][pos] != v)
				{
					continue;
				}
				adj[u][pos] = -1;
				fill(color.begin(), color.end(), 0);
				rep(k,1,n+1)
				{
					if(color[k] == 0)
					{
						if(isCyclic(k))
						{
							isCycle = true;
							break;
						}
					}
				}
				if(!isCycle)
				{
					cout << "YES";
					return 0;
				}
				adj[u][pos] = v;
			}
		}
	}
	cout << "NO";
	return 0;
}