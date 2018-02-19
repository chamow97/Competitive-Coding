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
const ll maxn = 3e5+100;
vec *adj = new vec[maxn];
vec parent(maxn, 0);
boolean visited(maxn, false);
ll maximum = 0;
string value = " ";
ll dp[maxn][30] = {0};

void dfs(ll s)
{
	visited[s] = true;
	for(auto i : adj[s])
	{
		if(!visited[i])
		{
			dfs(i);
		}
		rep(j,0,26)
		{
			dp[s][j] = max(dp[s][j], dp[i][j]);
			maximum = max(maximum, dp[s][j]);
		}
	}
	dp[s][value[s] - 'a']++;
	maximum = max(maximum, dp[s][value[s] - 'a']);
}



bool checkCycle(ll s)
{
	if(parent[s] == 2)
	{
		return false;
	}	
	if(parent[s] == 1)
	{
		return true;
	}
	parent[s] = 1;
	for(auto i : adj[s])
	{
		if(checkCycle(i))
		{
			return true;
		}
	}
	parent[s] = 2;
	return false;
}

int main()
{
	fastread;
	cin >> n >> m;
	cin >> value;
	value = " " + value;
	rep(i,0,m)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}
	rep(i,1,n+1)
	{
		if(!parent[i])
		{
			if(checkCycle(i))
			{
				cout << -1;
				return 0;
			}
		}
	}

	rep(i,1,n+1)
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}
	cout << maximum;

	return 0;
}