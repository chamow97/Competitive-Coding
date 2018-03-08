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

const ll maxn = 1e5 + 100;
vec *adj = new vec[maxn];
ll n, m, s;
vector<char> cl(maxn, 0);
bool visited[10][maxn];
vec path;
ll cycle;

void dfs(ll s)
{
	if(cycle == 1)
	{
		return;
	}
	if(cl[s] == 1)
	{
		cycle = 1;
		return;
	}
	cl[s] = 1;
	for(auto i : adj[s])
	{
		dfs(i);
	}
	cl[s] = 2;
}

ll solve(ll index, ll parent, ll mode)
{
	visited[mode][index] = true;
	if(adj[index].size() == 0)
	{
		return mode ^ 1;
	}
	for(auto i : adj[index])
	{
		if(visited[mode ^ 1][i])
		{
			continue;
		}
		ll curr = solve(i, index, mode ^ 1);
		if(curr == 1)
		{
			path.pb(i);
			return 1;
		}
	}
	return 0;
}

int main()
{
	fastread;
	cin >> n >> m;
	rep(i,1,n+1)
	{
		ll counter;
		cin >> counter;
		rep(j,0,counter)
		{
			ll val;
			cin >> val;
			adj[i].pb(val);
		}
	}
	cin >> s;
	if(solve(s, -1, 1) == 1)
	{
		cout << "Win\n";
		cout << s << ' ';
		for(auto i = path.rbegin(); i != path.rend(); i++)
		{
			cout << *i << ' ';
		}
		return 0;
	}
	dfs(s);
	if(cycle == 1)
	{
		cout << "Draw";
	}
	else
	{
		cout << "Lose";
	}
	return 0;
}