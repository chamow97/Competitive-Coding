//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
// #define mp make_pair
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

ll n, m, c;
const ll maxn = 1e5+10;
vec *adj = new vec[maxn];
boolean mp(maxn, false);	
boolean visited(maxn, false);
vec minArr(maxn, INF);
vec maxArr(maxn, 0);
vec incoming(maxn, 0);

void dfs(ll s)
{
	
	for(auto i : adj[s])
	{
		--incoming[i];
		if(incoming[i] <= 0)
		{
			visited[i] = true;
		}
		if(mp[i] == true)
		{
			minArr[i] = min(minArr[i], minArr[s] + 1);
			maxArr[i] = max(maxArr[i], maxArr[s] + 1);
		}
		else
		{
			minArr[i] = min(minArr[i], minArr[s]);
			maxArr[i] = max(maxArr[i], maxArr[s]);
		}
		if(visited[i] == true)
		{
			dfs(i);
		}
	}

}
int main()
{
	fastread;
	//input
	cin >> n >> c >> m;
	rep(i,0,c)
	{
		ll a;
		cin >> a;
		mp[a] = true;
	}
	rep(i,0,m)
	{
		ll u, v;
		cin >> u >> v;
		++incoming[v];
		adj[u].pb(v);
	}
	if(mp[1] == true)
	{
		maxArr[1] = 1;
		minArr[1] = 1;
	}
	else
	{
		maxArr[1] = 0;
		minArr[1] = 0;
	}
	dfs(1ll);
	cout << minArr[n] << ' ' << maxArr[n];
	return 0;
}
