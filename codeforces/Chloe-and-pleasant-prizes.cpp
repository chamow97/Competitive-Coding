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

struct nodeInfo {
	ll sum, maximum;
};

const ll MAXN = 2e5 + 10;
vec adj[MAXN];
vec cost(MAXN);
vector< nodeInfo > arr(MAXN);
boolean visited(MAXN, false);
ll n;
vec newAdj[MAXN];

void dfs(ll s)
{
	visited[s] = true;
	arr[s].sum = cost[s];
	arr[s].maximum = -INF;
	for(auto i : adj[s])
	{
		if(!visited[i])
		{
			newAdj[s].pb(i);
			dfs(i);
			arr[s].sum += arr[i].sum;
			arr[s].maximum = max(arr[s].maximum, arr[i].maximum);
		}
	}
	arr[s].maximum = max(arr[s].maximum, arr[s].sum);
}

int main()
{
	fastread;
	cin >> n;
	rep(i,1,n + 1)
	{
		cin >> cost[i];
	}
	rep(i,1,n)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
	ll ans = -INF;
	rep(i,1,n+1)
	{
		if(newAdj[i].size() <= 1)
		{
			continue;
		}
		multiset<ll, greater<ll>> ms;
		for(auto it : newAdj[i])
		{
			ms.insert(arr[it].maximum);
		}
		auto ite = ms.begin();
		ll sum = *ite;
		ite++;
		sum += (*ite);
		ans = max(ans, sum);
	}
	if(ans == -INF)
	{
		cout << "Impossible";
		return 0;
	}
	cout << ans;
	return 0;
}