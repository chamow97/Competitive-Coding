//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157

/*-------------------------------------------------------- */

typedef long long ll;
/*-------------------------------------------------------- */

int main()
{
	ll n, ans = 0;
	cin>>n;
	vector<ll> a(n);
	vector<ll> dp(100001,0);
	rep(i,0,n)
	{
		cin>>a[i];
	}
	if(n == 1)
	{
		cout<<"1";
		return 0;
	}
	rep(i,0,n)
	{
		ll maximum = 1;
		rep(j,2,sqrt(a[i])+1)
		{
			if(a[i] % j == 0)
			{
				maximum = max(maximum, dp[j] + 1);
				maximum = max(maximum, dp[a[i]/j] + 1);
			}
			dp[a[i]] = maximum;
			
		}
		ans = max(ans, maximum);

		rep(j,2,sqrt(a[i])+1)
		{
			if(a[i] % j == 0)
			{
				dp[j] = maximum;
				dp[a[i]/j] = maximum;
			}
		}
	}
	cout<<ans;
    return 0;
}
