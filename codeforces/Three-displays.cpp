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

int main()
{
	fastread;
	ll n;
	cin >> n;
	ll dp[5][n+10];
	vec arr(n+10);
	vec cost(n+10);
	rep(i,0,5)
	{
		rep(j,0,n+1)
		{
			dp[i][j] = INF;
		}
	}
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	rep(i,1,n+1)
	{
		cin >> cost[i];
		dp[1][i] = cost[i];
	}
	rep(i,1,n+1)
	{
		rep(j,1,i)
		{
			if(arr[j] < arr[i])
			{
				rep(k,1,4)
				{
					dp[k][i] = min(dp[k][i], dp[k-1][j] + cost[i]);
				}
			}
		}
	}
	ll ans = INF;
	rep(i,1,n+1)
	{
		ans = min(ans, dp[3][i]);
	}
	if(ans == INF)
	{
		ans = -1;
	}
	cout << ans;
	return 0;
}