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
ll n, m, t, k ,p;
const ll maxn = 1e5;
vec pine(maxn,0);
boolean visited(maxn, false);
vecpair *adj = new vecpair[maxn];
void dijkstras(ll s, vec &distance)
{
	priority_queue< pair<ll, ll>, vecpair,  greater< pair<ll, ll> > > min_heap;
	min_heap.push( mp(0,s) );
	distance[s] = 0;
	while( !min_heap.empty() )
	{
		ll u = min_heap.top().second;
		// cout << u << ' ';
		min_heap.pop();
		vecpair :: iterator i;
		if(visited[u] == true)
		{
			continue;
		}
		visited[u] = true;

		for(i = adj[u].begin(); i != adj[u].end(); i++ )
		{

			ll v = (*i).first;
			ll w = (*i).second;
			ll extra = 0;
			if(visited[v] == true)
			{
				continue;
			}
			if(pine[v] != 0)
			{
				extra = k;
			}
			if( distance[v] > (distance[u] + w + extra))
			{
				distance[v] = distance[u] + w + extra;
				min_heap.push( mp( distance[v], v ) );
			}
		}

	}

}

int main()
{
	fastread;
	cin >> n >> m >> t >> k >> p;
	vec distance(maxn, INF);
	rep(i,0,p)
	{
		ll pos;
		cin >> pos;
		--pos;
		pine[pos] = k;
	}
	rep(i,0,m)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		w *= 60;
		--u;
		--v;
		adj[u].pb(mp(v,w));
	}
	dijkstras(0ll, distance);
	if(distance[n-1] > (t * 60))
	{
		distance[n-1] = -1;
	}
	cout << distance[n-1];
	return 0;
}
