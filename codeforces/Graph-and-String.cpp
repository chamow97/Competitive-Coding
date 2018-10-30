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
const ll MAXN = 600;
vec adj[MAXN];
vec match(MAXN, -1);

int main()
{
	fastread;
	cin >> n >> m;
	rep(i,0,m)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep(i,1,n+1)
	{
		sort(adj[i].begin(), adj[i].end());
	}
	// Make nodes connected to all other nodes as 'b' or 1
	rep(i,1,n+1)
	{
		if(adj[i].size() ==  n - 1)
		{
			match[i] = 1;
		}
	}
	rep(i,1,n+1)
	{
		if(match[i] == 1)
		{
			continue;
		}
		else if(match[i] == -1)
		{
			match[i] = 0;
		}
		rep(j,1,n+1)
		{
			if(i == j)
			{
				continue;
			}
			if(match[j] == 1)
			{
				continue;
			}
			ll temp = match[j];
			if(binary_search(adj[i].begin(), adj[i].end(), j))
			{
				if(match[i] == 0)
				{
					match[j] = 0;
				}
				else
				{
					match[j] = 2;
				}
			}
			else
			{
				if(match[i] == 0)
				{
					match[j] = 2;
				}
				else
				{
					match[j] = 0;
				}
			}
			if(temp != match[j] && temp != -1)
			{
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes\n";
	rep(i,1,n+1)
	{
		cout << char(match[i] + 'a');
	}
	return 0;
}