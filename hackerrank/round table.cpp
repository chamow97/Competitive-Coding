//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define MOD 1000000007
/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;

/*-------------------------------------------------------- */

int main()
{
    ll n;
    ll i, j;
    cin>>n;
    vector<ll> dp(1001,0);
    dp[0] = 1;
    for(i=2; i<=n; i+=2)
    {
        ll ans = 0;
        for(j=2; j<=i; j+=2)
        {
            if( j == 2 )
            {
                ans = ((ans + dp[i-2]) % MOD);
            }
            else
            {
                ans = (ans + (((dp[i-j])) * ((dp[j-2])) )) % MOD;
            }
        }
        //cout<<ans<<" ";
        dp[i] = ans;
    }
    cout<<dp[n]%MOD;
	return 0;
}
