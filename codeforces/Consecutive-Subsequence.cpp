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
	map<ll, ll> m;
	cin >> n;
	vec dp(n+1, 0);
	vec arr(n+1, 0);
	ll maximum = 0, prevVal = 0;
	rep(i,1,n+1)
	{
		cin >> arr[i];
		m[arr[i]] = i;
		dp[i] = max(dp[m[arr[i] - 1]] + 1, dp[i]); 
		if(maximum < dp[i])
		{
			maximum = dp[i];
			prevVal = arr[i];
		}
	}
	vec ans;
	per(j,n,1)
	{
		if(dp[j] == maximum && arr[j] == prevVal)
		{
			--maximum;
			--prevVal;
			ans.pb(j);	
		}
	}
	cout << ans.size() << '\n';
	reverse(ans.begin(), ans.end());
	rep(i,0,ans.size())
	{
		cout << ans[i] << ' ';
	}
	return 0;
}