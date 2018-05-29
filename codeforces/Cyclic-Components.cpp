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

const ll MAXN = 2e5 + 100;
vec adj[MAXN];
vec visited(MAXN, false);
bool isCyclic = true;

void cycleCheck(ll s) 
{
	visited[s] = true;
	if(adj[s].size() != 2)
	{
		isCyclic = false;
	}
	for(auto i : adj[s])
	{
		if(!visited[i])
		{
			cycleCheck(i);
		}
	}
}

int main()
{
	fastread;
	ll n, m, ans = 0;
	cin >> n >> m;
	rep(i,1,m+1)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep(i,1,n+1)
	{
		if(!visited[i])
		{
			isCyclic = true;
			cycleCheck(i);
			if(isCyclic)
			{
				++ans;
			}
		}
	}
	cout << ans;
	return 0;
}