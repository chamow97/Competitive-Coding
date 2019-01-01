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

ll n;
const ll MAXN = 1e5 + 10;
vec adj[MAXN];
vec color(MAXN, 0);
set<ll> clr;

void dfs(ll s, ll par)
{
	clr.insert(color[s]);
	for(auto i : adj[s])
	{
		if(i != par)
		{
			dfs(i, s);
		}
	}
}

bool solve(ll s)
{
	bool ok = true;
	for(auto i : adj[s])
	{
		clr.clear();
		dfs(i, s);
		if(clr.size() > 1)
		{
			ok = false;
		}
	}
	return ok;
}

int main()
{
	fastread;
	cin >> n;
	rep(i,0,n-1)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep(i,1,n+1)
	{
		cin >> color[i];
	}
	ll node1 = -1, node2 = -1;
	rep(i,1,n + 1)
	{
		for(auto j : adj[i])
		{
			if(color[i] != color[j])
			{
				node1 = i;
				node2 = j;
				break;
			}
		}
		if(node1 != -1)
		{
			break;
		}
	}
	if(node1 == -1)
	{
		cout << "YES\n 1";
		return 0;
	}
	bool isPossible1 = solve(node1);
	bool isPossible2 = solve(node2);
	if(isPossible1 == isPossible2 and isPossible1 == false)
	{
		cout << "NO";
	}
	else
	{
		if(isPossible1)
		{
			cout << "YES\n" << node1;
		}
		else
		{
			cout << "YES\n" << node2;
		}
	}
	return 0;
}