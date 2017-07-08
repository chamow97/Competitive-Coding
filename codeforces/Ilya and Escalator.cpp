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
ll n, t;
double dp[2001][2001] = {-1};
double p;	

int main()
{
	fastread;
	cin>>n>>p>>t;
	dp[0][0] = 1.0;
	rep(i,1,n+1)
	{
		dp[i][0] = 0.0;
	}
	rep(i,1,t+1)
	{
		dp[0][i] = (1-p)*dp[0][i-1];
	}
	rep(i,1,n+1)
	{
		rep(j,1,t+1)
		{
			if(i == n)
			{
				dp[i][j] = (p*(dp[i-1][j-1])) + (dp[i][j-1]);
				continue;
			}
			dp[i][j] = (p*(dp[i-1][j-1])) + (1-p)*(dp[i][j-1]);
		}
	}
	double ans = 0.0;
	rep(i,1,n+1)
	{
		ans += (i*(dp[i][t]));
	}
	printf("%.9f", ans);	
	return 0;
}