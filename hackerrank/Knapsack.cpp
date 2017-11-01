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
	ll t, n, k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		vec arr(n+1, 0);
		rep(i,0,n)
		{
			cin>>arr[i+1];
		}
		ll dp[n+10][k+10];
		rep(i,0,n+1)
		{
			rep(j,0,k+1)
			{
				dp[i][j] = 0;
			}
		}
		rep(i,0,n+1)
		{
			dp[i][0] = 1;
		}
		rep(i,1,n+1)
		{
			rep(j,1,k+1)
			{
				if((j-arr[i]) >= 0)
				dp[i][j] = dp[i-1][j] | dp[i][j-arr[i]];
				else
					dp[i][j] = dp[i-1][j];
			}
		}
		ll val = 0;
		rep(j,1,k+1)
		{
			if(dp[n][j] == 1)
			{
				val = max(val, j);
			}
		}
		
		cout<<val<<'\n';
		
	}
	return 0;
}
