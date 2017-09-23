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
ll n, x;
ll maxn = 2e5+10;
vec *adj = new vec[maxn];
vec distanceForAlice(maxn, INF);
vec distanceForBob(maxn, INF);
void dfs(boolean &visited, ll s, vec &distanceForAlice)
{
	visited[s] = true;
	vecit it;
	for(it = adj[s].begin(); it != adj[s].end(); it++)
	{
		if(visited[*it] == false)
		{
//		    cout<<*it<<" ";
			distanceForAlice[*it] = distanceForAlice[s] + 1;
			dfs(visited, *it, distanceForAlice);
		}
	}
}
void solve()
{
	cin>>n>>x;
	rep(i,0,n-1)
	{
		ll u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	boolean visited(maxn, false);
	distanceForAlice[1] = 0;
	dfs(visited, 1ll, distanceForAlice);
	distanceForBob[x] = 0;
	fill(visited.begin(), visited.end(), false);
	dfs(visited, x, distanceForBob);
    ll minDistance = distanceForAlice[x];
    ll ans = minDistance;
    rep(i,1,n+1)
    {
        if(distanceForBob[i] < distanceForAlice[i])
        {
            ans = max(ans, 2*distanceForAlice[i]);
        }
    }
    cout<<ans;
}
int main()
{
	fastread;
	solve();
	return 0;
}
