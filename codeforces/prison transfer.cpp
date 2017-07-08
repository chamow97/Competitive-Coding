
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
    ll n, t, c, ans = 0;
    cin>>n>>t>>c;
    vector<ll> arr(n);
    ll counter = 0;
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    rep(i,0,n)
    {
        if(arr[i] <= t)
        {
            counter += 1;
        }
        else
        {
            if(counter >= c)
            {
                ans += (counter - c + 1);
            }
            counter = 0;
        }
    }
    if(counter >= c)
            {
                ans += (counter - c + 1);
            }

    cout<<ans;

	return 0;
}
