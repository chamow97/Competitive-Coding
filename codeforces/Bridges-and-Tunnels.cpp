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
#define INF 1e18
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

void dijkstras( vecpair *adj, vec &distance, ll s )
{
	priority_queue< pair<ll, ll>, vecpair,  greater< pair<ll, ll> > > min_heap;
	min_heap.push( mp(0,s) );
	distance[s] = 0;
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
				min_heap.push( mp( distance[v], v ) );
			}
		}

	}

}



/* ------------------------------------------------------------------------- */

const ll mult = 4e9+1;

int main()
{
	ll n, m, p;
	cin >> n >> m >> p;
	vecpair adj[n];
	rep(i,0,m)
	{
		ll u, v, w;
		char c;
		cin >> u >> v >> w >> c;
		if(c == 'O')
		{
			adj[u].pb(mp(v, w * mult));
			adj[v].pb(mp(u, w * mult));
		}
		else
		{
			adj[u].pb(mp(v, w));
			adj[v].pb(mp(u, w));
		}
	}
	rep(i,0,p)
	{
		ll u, v;
		cin >> u >> v;
		vec distance(n, INF);
		dijkstras(adj, distance, u);
		if(distance[v] == INF)
		{
			cout << "IMPOSSIBLE";
		}
		else
		{
			ll indoor = distance[v] % mult;
			ll outdoor = distance[v] / mult;
			ll result = indoor + outdoor;
			cout << outdoor << ' ' << indoor;
		}
		cout << '\n';
	}
	return 0;
}