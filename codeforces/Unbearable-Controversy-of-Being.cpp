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

int main()
{
	fastread;
	ll n, m;
	cin >> n >> m;
	ll graph[n+10][n+10];
	vec *adj = new vec[n+10];
	memset(graph, 0, sizeof(graph));
	rep(i,0,m)
	{
		ll u, v;
		cin >> u >> v;
		graph[u][v] = 1;
		adj[u].pb(v);
	}
	ll sum = 0;
	rep(i,1,n+1)
	{
		rep(j,1,n+1)
		{
			if(i != j)
			{
				ll count = 0;
				rep(k,0,adj[i].size())
				{
					ll now = adj[i][k];
					if(graph[now][j] == 1 && now != i && now != j)
					{
						++count;
					}
				}
				if(count > 1)
				{
					sum += ((count*(count - 1))/2);
				}
			}
		}
	}
	cout << sum;
	return 0;
}
