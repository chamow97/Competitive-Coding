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


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;


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
    while(1)
    {
        ll w, n;
    cin>>w>>n;
    if(w == 0 && n == 0)
    {
        break;
    }
    ll dp[n+1][w+1];
    rep(i,0,n+1)
    {
        rep(j,0,w+1)
        {
            dp[i][j] = 0;
        }
    }
    ll val[n+1], weight[n+1];
    rep(i,1,n+1)
    {
        cin>>val[i]>>weight[i];
    }

    rep(i,1,n+1)
    {
        rep(j,1,w+1)
        {
            if(val[i] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                if(dp[i-1][j] >= weight[i] + dp[i-1][j-val[i]])
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                    dp[i][j] = weight[i] + dp[i-1][j-val[i]];
            }
        }
    }
    ll minVal = -1;
    rep(j,1,w+1)
    {
        if(dp[n][j] == dp[n][w])
        {
            minVal = j;
            break;
        }
    }
    cout<<minVal<<" "<<dp[n][w]<<'\n';
    }

	return 0;
}
