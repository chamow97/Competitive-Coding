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
typedef vector<bool> boolean;

/*-------------------------------------------------------- */

int main()
{
    vector<ll> dp(56,0);
    dp[1] = 2;
    rep(i,2,56)
    {
        dp[i] = dp[i-1] + (pow(2,i));
    }
    dp[55] -= 2;
    ll n;
    cin>>n;
    cout<<dp[n];
	return 0;
}
