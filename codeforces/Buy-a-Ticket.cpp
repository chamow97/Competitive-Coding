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
ll n, m;
const ll maxn = 3e5 + 200;
vecpair G[maxn];
vec dist(maxn);
priority_queue< pair<ll, ll>, vecpair,  greater< pair<ll, ll> > > s;

void Dijkstras()
{
	rep(i,1,n+1)
	{
		s.push(mp(dist[i], i));
	}
	while(!s.empty())
	{
		auto now = s.top();
		s.pop();
		ll u = now.second;
		if(dist[u] == now.first)
		{
			for(auto i : G[u])
			{
				ll w = i.second;
				ll v = i.first;
				if(dist[v] > dist[u] + w)
				{
					dist[v] = dist[u] + w;
					s.push(mp(dist[v], v)); 
				}
			}
		}
			
	}

}

int main()
{
	fastread;
	cin >> n >> m;
	rep(i,1,m+1)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		w *= 2;
		G[u].pb(mp(v, w));
		G[v].pb(mp(u, w));
	}
	rep(i,1,n+1)
	{
		cin >> dist[i];
	}
	Dijkstras();
	rep(i,1,n+1)
	{
		cout << dist[i] << ' ' ;
	}
	return 0;
}