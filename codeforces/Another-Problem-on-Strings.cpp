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
	ll k;
	ll ans = 0;
	string str;
	cin >> k;
	cin >> str;
	ll n = str.length();
	str = "0" + str;
	vec dp(n+1, 0);
	rep(i,1,n+1)
	{
		ll val = 0;
		if(str[i] == '1')
		{
			val = 1;
		}
		dp[i] = dp[i-1] + val;
	}
	rep(i,1,n+1)
	{
		ll nowVal = dp[i-1] + k;
		ll ptr1 = lower_bound(dp.begin()+i, dp.end(), nowVal) - dp.begin();
		ll ptr2 = upper_bound(dp.begin()+i, dp.end(), nowVal) - dp.begin();
		if(dp[n] < nowVal)
		{
			continue;
		}
		ans += (ptr2 - ptr1);
	}
	cout << ans;
	return 0;
}