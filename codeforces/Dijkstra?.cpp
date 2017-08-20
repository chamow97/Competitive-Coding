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


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;
#define vecpair vector< pair<ll, ll > >

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

void dijkstras(vector< pair<ll, ll> > *adj, boolean &visited, vec &distance, vec &parent, ll s)
{
	priority_queue< pair<ll, ll>, vecpair,  greater< pair<ll, ll> > > min_heap;
	min_heap.push( mp(0ll,s) );
	distance[s] = 0;
	parent[0] = 0;
	while( !min_heap.empty() )
	{
		ll u = min_heap.top().second;
		min_heap.pop();
		vecpair :: iterator i;

		for( i = adj[u].begin(); i != adj[u].end(); i++ )
		{
			ll v = (*i).first;
			ll w = (*i).second;

			if( distance[v] > distance[u] + w )
			{
				distance[v] = distance[u] + w;
				parent[v] = u;
				min_heap.push( mp( distance[v], v ) );
			}
		}

	}
}

int main()
{
	fastread;
	ll n, m;
	cin>>n>>m;

	vector< pair<ll, ll> > *adj = new vector< pair<ll, ll> >[n];
	rep(i,0,m)
	{
		ll u, v, w;
		cin>>u>>v>>w;
		--u, --v;
		adj[u].pb(mp(v,w));
		adj[v].pb(mp(u,w));
	}
	boolean visited(n, false);
	vec distance(n, INF);
	vec parent(n, -1);
	dijkstras(adj, visited, distance, parent, 0ll);
	vec shortestPath;
	ll now = INF;
	now = parent[n-1];
	if(now == -1)
	{
		cout<<now;
		return 0;
	}
	shortestPath.pb(n);
	while(now > 0)
	{
		shortestPath.pb(now + 1);
		now = parent[now];
	}
	shortestPath.pb(1);
	per(j,shortestPath.size()-1,0)
	{
		cout<<shortestPath[j]<<" ";
	}

	return 0;
}