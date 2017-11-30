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
boolean visited(2011,false);
vec *adj = new vec[1020];
vec maximum(2011, 0);

ll ans = 0;
		
void dfs(ll s)
{
	visited[s] = true;
	for(auto i : adj[s])
	{
		if(visited[i] == false)
		{
			dfs(i);
		}
		//starting at s, we find best possible
		maximum[s] = max(maximum[i] + 1, maximum[s]);

	}
	//we find the best of s
	ans = max(ans, maximum[s]);
}

int main()
{
	fastread;
	ll n, k;
	cin >> n >> k;
	ll position[k+10][n+10];
	rep(i,1,k+1)
	{
		rep(j,1,n+1)
		{
			ll val;
			cin >> val;
			position[i][val] = j;

		}
	}
	rep(i,1,n+1)
	{
		rep(j,1,n+1)
		{
			if(i == j)
			{
				continue;
			}
			bool now = true;
			rep(l,1,k+1)
			{
				if(position[l][i] >= position[l][j])
				{
					now = false;
				}
			}
			if(now == true)
			{
				//it means all the row value of one is > all the 
				//row value of another column
				adj[i].pb(j);
			}
		}

	}
	//now we have the sequence, we should find which gives best answer
	rep(i,1,n+1)
	{
		if(visited[i] == false)
		{
			dfs(i);
		}
	}
	cout << ans + 1;
	return 0;
}
