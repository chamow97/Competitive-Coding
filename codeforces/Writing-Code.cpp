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

ll dp[4][541][541];
int main()
{
	fastread;
	ll n, m, k, mod;
	memset(dp, 0, sizeof dp);
	cin >> n >> m >> k >> mod;
	vec arr(n + 1);
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	dp[0][0][0] = 1 % mod;
	rep(i,1,n+1)
	{
		ll curr = (i % 2);
		ll prev = 1 - curr;
		rep(j,0,m+1)
		{
			rep(l,0,k+1)
			{
				dp[curr][j][l] = dp[prev][j][l];
				if(j > 0 && l - arr[i] >= 0)
				{
					dp[curr][j][l] += dp[curr][j - 1][l - arr[i]];
				}
				dp[curr][j][l] %= mod;
			}
		}
	}
	ll ans = 0;
	rep(i,0,k+1)
	{
		ans = ((ans % mod) + (dp[n % 2][m][i] % mod)) % mod;
	}
	cout << ans;
	return 0;
}