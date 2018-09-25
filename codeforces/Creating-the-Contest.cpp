//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vecit vector<int> :: iterator
#define vecpit vector< pair<int, int> > :: iterator
#define f first
#define s second


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;
typedef vector< pair<int, int> > vecpair;


/*-------------------------------------------------------- */
int main()
{
	fastread
	ll n;
	cin >> n;
	vec arr(n, 0);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	vec dp(n, 0);
	dp[n-1] = 1;
	per(j,n-2,0)
	{
		ll lb = upper_bound(arr.begin(), arr.end(), arr[j]) - arr.begin();
		if(lb != n)
		{
			if(arr[lb] <= 2 * arr[j])
			{
				dp[j] = 1 + dp[lb];
			}
			else
			{
				dp[j] = 1;
			}
		}
	}
	ll maximum = 0;
	rep(i,0,n)
	{
		maximum = max(maximum, dp[i]);
	}
	cout << maximum;
	return 0;
}