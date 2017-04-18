//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157

/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;

/*-------------------------------------------------------- */

void shortestPath(vector< pair<ll, ll> > *adj, ll s, vector<ll> &distance )
{
	priority_queue< pair<ll, ll>, vector< pair<ll, ll> >, greater< pair< ll, ll> > > pq;
	pq.push(make_pair(0, s));
	distance[s] = 0;
	while(!pq.empty())
	{
		ll u = pq.top().second;
		pq.pop();
		vector< pair<ll, ll> > :: iterator it;
		for ( it = adj[u].begin(); it != adj[u].end(); it ++ )
		{
			ll v = (*it).first;
			ll w = (*it).second;

			if( distance[v] > distance[u] + w )
			{
				distance[v] = distance[u] + w;
				pq.push( make_pair(distance[v], v) );
			}
		}
	}
}

/*-------------------------------------------------------- */

int main()
{
    ll t, n, k, x, m, s, u, v, w;
    scanf("%lld", &t);
    while(t--)
    {
    	scanf("%lld %lld %lld %lld %lld", &n, &k, &x, &m, &s);
    	ll length = 1000000000000000000, position = -1;
    	--s;
    	vector< pair<ll, ll> > *adj = new vector< pair<ll, ll> >[n+1];
    	vector<ll> distance(n+1, 1000000000000000000);
    	rep(i,0,m)
    	{
    		scanf("%lld %lld %lld", &u, &v, &w);
    		u --;
    		v --;

    		adj[u].pb(make_pair(v,w));
    		adj[v].pb(make_pair(u,w));
    	}
        rep(i,0,k)
        {
            adj[i].pb(make_pair(n,x));
            adj[n].pb(make_pair(i,0));
        }
    	shortestPath(adj, s, distance);
        rep(i,0,n)
        {
            printf("%lld ", distance[i]);
        }
        printf("\n");


    }

	return 0;
}
