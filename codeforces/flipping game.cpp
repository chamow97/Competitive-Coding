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
    ll n, ones = 0, maximum = 0, ans = 0;
    cin>>n;
    vector<ll> arr(n+1,0), dp(n+1,0);
    rep(i,1,n+1)
    {
        cin>>arr[i];
        if(arr[i] == 1)
        {
            ++ones;
            dp[i] = -1;
        }
        else
        {
            dp[i] = 1;
        }
    }
    if( ones == n)
    {
        cout<<n-1;
        return 0;
    }
    rep(i,1,n+1)
    {
        ans += dp[i];
        if(ans < 0)
        {
            ans = 0;
        }
        maximum = max(maximum, ans);
    }
    cout<<maximum + ones;
    return 0;
}
