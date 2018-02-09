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

ll dp[200][200][100];
ll n, m;
vecpair *adj = new vecpair[100000];

bool solve(ll u, ll v, ll cost)
{
	if(dp[u][v][cost] != -1)
	{
		return dp[u][v][cost] == 0;
	}
	bool win = false;
	rep(i,0,adj[u].size())
	{
		ll nextNode = adj[u][i].f;
		ll nextChar = adj[u][i].s;
		if(nextChar >= cost && solve(v, nextNode, nextChar) == false)
		{
			win = true;
		}
	}
	if(win == true)
	{
		dp[u][v][cost] = 0;
	}
	else
	{
		dp[u][v][cost] = 1;
	}
	return dp[u][v][cost] == 0;

}

int main()
{
	fastread;
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	rep(i,0,m)
	{
		ll u, v;
		char ch;
		cin >> u >> v >> ch;
		adj[u].pb(mp(v, ch - 'a'));
	}
	rep(i,1,n+1)
	{
		rep(j,1,n+1)
		{
			if(solve(i, j, 0))
			{
				cout << 'A';
			}
			else
			{
				cout << 'B';
			}
		}
		cout << '\n';
	}
	return 0;
}