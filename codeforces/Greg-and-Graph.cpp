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
	ll n;
	cin >> n;
	ll adj[n+10][n+10];
	vec deletedVertex(n + 1, 0);
	boolean visited(n + 1, false);
	vec ans(n + 1, 0);
	rep(i, 1, n + 1)
	{
		rep(j, 1, n + 1)
		{
			cin >> adj[i][j];
		}
	}
	rep(i, 1, n + 1)
	{
		cin >> deletedVertex[i];
	}

	per(k, n, 1)
	{
		//we mark the visited vertex
		visited[deletedVertex[k]] = true;
		rep(i, 1, n + 1)
		{
			rep(j, 1, n + 1)
			{
				adj[i][j] = min(adj[i][j], adj[i][deletedVertex[k]] + adj[deletedVertex[k]][j]);
			}
		}
		ll current = 0;
		rep(i, 1, n + 1)
		{
			rep(j, 1, n + 1)
			{
				if(visited[i] && visited[j])
				{
					current += adj[i][j];
				}
			}
		}
		ans[k] = current;
	}
	rep(i, 1, n + 1)
	{
		cout << ans[i] << ' '; 
	}
	return 0;
}