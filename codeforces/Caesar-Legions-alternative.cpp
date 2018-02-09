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
ll dp[110][110][10];

void solve()
{
	memset(dp, sizeof(dp), 0);

	rep(i,1,k1+1)
	{
		dp[i][0][0] = 1;
		dp[i][0][1] = 0; 
	}	

	rep(j,1,k2+1)
	{
		dp[0][j][1] = 1;
		dp[0][j][0] = 0;
	}
	ll k = 0;
	rep(i,1,n1+1)
	{
		rep(j,1,n2+1)
		{
			for(k = 1; k <= k1 && (i - k) >= 0; k++)
			{
				dp[i][j][0] += dp[i-k][j][1];
			}
			dp[i][j][0] %= MODULO;
			
			for(k = 1; k <= k2 && (j - k) >= 0; k++)
			{
				dp[i][j][1] += dp[i][j-k][0];
			}
			dp[i][j][1] %= MODULO;
		}
	}

	cout << (dp[n1][n2][0] + dp[n1][n2][1]) % MODULO;
}

int main()
{
	fastread;
	cin >> n1 >> n2 >> k1 >> k2;
	solve();
	return 0;
}
