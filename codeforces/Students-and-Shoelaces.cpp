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

int main()
{
	fastread;
	ll n, m, ans = 0;
	cin >> n >> m;
	vec adj[n+1];
	rep(i,0,m)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	bool isOver = false;
	while(!isOver)
	{
		ll currSize = 0;
		vec nowNodes;
		rep(i,1,n+1)
		{
			if(adj[i].size() == 1)
			{
				++currSize;
				nowNodes.pb(i);
			}
		}
		if(currSize == 0)
		{
			isOver = true;
			break;
		}
		++ans;
		rep(i,0,nowNodes.size())
		{
			ll now = nowNodes[i];
			if(adj[now].size() == 1)
			{
				ll next = *adj[now].begin();
				adj[next].erase(find(adj[next].begin(), adj[next].end(), now));
				adj[now].clear(); 
			}
		}
	}
	cout << ans;
	return 0;
}