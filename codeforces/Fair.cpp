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

const ll MAXN = 1e5 + 100;
vec arr[110];
vec adj[MAXN];
ll n, m, k, s;
ll cost[MAXN][110];
boolean visited(MAXN, false);
queue<ll> q;

void bfs(ll s)
{
	while(!q.empty())
	{
		ll top = q.front();
		q.pop();
		for(auto i : adj[top])
		{
			if(!visited[i])
			{
				cost[i][s] = cost[top][s] + 1;
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	fastread;
	memset(cost, -1, sizeof(MAXN));
	cin >> n >> m >> k >> s;
	rep(i,1,n+1)
	{
		ll type;
		cin >> type;
		arr[type].pb(i);
	}
	rep(i,1,m+1)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep(i,1,101)
	{
		fill(visited.begin(), visited.end(), false);
		while(!q.empty())
		{
			q.pop();
		}
		for(auto it : arr[i])
		{
			visited[it] = true;
			cost[it][i] = 0;
			q.push(it);
		}
		bfs(i);
	}
	rep(i,1,n+1)
	{
		vec now;
		rep(j,1,k+1)
		{
			if(cost[i][j] != -1)
			{
				now.pb(cost[i][j]);
			}
		}
		sort(now.begin(), now.end());
		cout << accumulate(now.begin(), now.begin() + s, 0) << ' ';
	}
	return 0;
}