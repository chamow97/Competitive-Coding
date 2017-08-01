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


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;


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

void dfs(ll pos, vec &x, vec &y, boolean &visited, ll n)
{
	visited[pos] = true;
	rep(i,0,n)
	{
		if(visited[i] == false)
		{
			if(x[i] == x[pos] || y[i] == y[pos])
			{
				dfs(i, x, y, visited, n);
			}
		}
	}
}

int main()
{
	fastread;
	ll n;
	cin>>n;
	vec x(n,0), y(n,0);
	rep(i,0,n)
	{
		cin>>x[i]>>y[i];
	}
	ll ans = 0;
	boolean visited(n,false);
	rep(i,0,n)
	{
		if(visited[i] == false)
		{
			++ans;
			dfs(i, x, y, visited, n);
		}
	}
	cout<<ans-1;
	return 0;
}