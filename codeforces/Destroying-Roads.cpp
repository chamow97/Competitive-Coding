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

const ll MAXN = 4e3;
ll n, m;
vec adj[MAXN];
ll dist[MAXN][MAXN];
vec path(MAXN, 0);

void bfs(ll s)
{
	queue<ll> q;
	q.push(s);
	dist[s][s] = 0;
	while(!q.empty())
	{
		ll top = q.front();
		q.pop();
		for(auto i : adj[top])
		{
			if(dist[s][i] == -1)
			{
				dist[s][i] = dist[s][top] + 1;
				q.push(i);
			}
		}
	}
}

int main()
{
	fastread;
	cin >> n >> m;
	memset(dist, -1, sizeof(dist));
	rep(i,0,m)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ll s1, t1, l1, s2, t2, l2;
	cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
	rep(i,1,n+1)
	{
		bfs(i);
	}
	if(dist[s1][t1] > l1 || dist[s2][t2] > l2)
	{
		cout << -1;
		return 0;
	}
	ll ans = dist[s1][t1] + dist[s2][t2];
	rep(i,1,n+1)
	{
		rep(j,1,n+1)
		{
			ll now1 = dist[s1][i] + dist[i][j] + dist[j][t1];
			ll now2 = dist[s2][i] + dist[i][j] + dist[j][t2];
			if(now1 <= l1 && now2 <= l2)
			{
				ans = min(ans, now1 + now2 - dist[i][j]);
			}
			now2 = dist[s2][j] + dist[j][i] + dist[i][t2];
			if(now1 <= l1 && now2 <= l2)
			{
				ans = min(ans, now1 + now2 - dist[j][i]);
			}
			now1 = dist[s1][j] + dist[j][i] + dist[i][t1];
			now2 = dist[s2][i] + dist[i][j] + dist[j][t2];
			if(now1 <= l1 && now2 <= l2)
			{
				ans = min(ans, now1 + now2 - dist[j][i]);
			}
			now2 = dist[s2][j] + dist[j][i] + dist[i][t2];
			if(now1 <= l1 && now2 <= l2)
			{
				ans = min(ans, now1 + now2 - dist[j][i]);
			}
				
		}
	}
	cout << m - ans;
	return 0;
}