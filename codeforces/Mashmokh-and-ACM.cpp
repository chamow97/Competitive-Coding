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
	ll n, k;
	cin >> n >> k;
	ll dp[k+10][n+10];
	memset(dp, 0, sizeof(dp));
	rep(i,0,n+1)
	{
		dp[1][i] = 1;
	}
	rep(i,2,k+1)
	{
		rep(j,1,n+1)
		{
			for(ll l = j; l <= n; l+=j)
			{
				//editorial for optimization
				//nkln(n)
				dp[i][j] = (dp[i][j] + dp[i-1][l]) % MODULO; 
			}
		}
	}
	ll ans = 0;
	rep(i,1,n+1)
	{
		ans = (ans + dp[k][i]) % MODULO;
	}
	cout << ans;
	return 0;
}
