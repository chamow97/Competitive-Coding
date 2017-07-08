
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

ll dp[600][600] = {0};

void solve(ll n, vector<ll> a)
{
    rep(i,0,n)
    {
        dp[i][i] = 1;
    }
    per(i,n-1,0)
    {
        rep(j,i+1,n)
        {
            dp[i][j] = 1 + dp[i+1][j];
            if(a[i] == a[i+1])
            {
                dp[i][j] = min(dp[i][j], 1 + dp[i+2][j]);
            }
            rep(k,i+2,j+1)
            {
                if(a[i] == a[k])
                {
                    dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k+1][j]);
                }
            }
        }
    }
}

int main()
{
    ll n;
    cin>>n;
    vector<ll> arr(n,0);
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    solve(n, arr);
    cout<<dp[0][n-1];
	return 0;
}
