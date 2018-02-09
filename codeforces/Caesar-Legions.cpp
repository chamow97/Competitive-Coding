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
#define MODULO 100000000
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

ll n1, n2, k1, k2;
ll dp[110][110][5];

ll getAnswer(ll n1, ll n2, ll z)
{
	if(dp[n1][n2][z] >= 0)
	{
		return dp[n1][n2][z];
	}
	if(n1 == 0 && n2 == 0)
	{
		dp[n1][n2][z] = 1;
		return dp[n1][n2][z];
	}
	if(n1 == 0)
	{
		if(z == 0)
		{
			dp[n1][n2][z] = 0;
		}
		else
		{
			if(n2 <= k2)
			{
				dp[n1][n2][z] = 1;
			}
			else
			{
				dp[n1][n2][z] = 0;
			}
		}
		return dp[n1][n2][z];
	}
	if(n2 == 0)
	{
		if(z == 1)
		{
			dp[n1][n2][z] = 0;
		}
		else
		{
			if(n1 <= k1)
			{
				dp[n1][n2][z] = 1;
			}
			else
			{
				dp[n1][n2][z] = 0;
			}
		}
		return dp[n1][n2][z];
	}
	ll now = 0;
	if(z == 0)
	{
		rep(i,1,min(k1, n1) + 1)
		{
			now = (now % MODULO + getAnswer(n1 - i, n2, 1) % MODULO) % MODULO;
		}
	}
	else
	{
		rep(i,1,min(k2, n2) + 1)
		{
			now = (now % MODULO + getAnswer(n1, n2 - i, 0) % MODULO) % MODULO;
		}
	}
	dp[n1][n2][z] = now;
	return dp[n1][n2][z];
}

int main()
{
	fastread;
	cin >> n1 >> n2 >> k1 >> k2;
	memset(dp, -1, sizeof(dp));
	ll ans = (getAnswer(n1, n2, 0ll) % MODULO + getAnswer(n1, n2, 1ll) % MODULO) % MODULO;
	cout << ans;
	return 0;
}
