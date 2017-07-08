
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
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n,0), b(n,0);
    rep(i,0,n)
    {
        cin>>a[i];
    }
    rep(i,0,n)
    {
        cin>>b[i];
    }
    ll low = 0, high = 2e9;
    ll extra = 0;
    while(low < high)
    {
        ll mid = (low + high) >> 1;
        extra = 0;
        rep(i,0,n)
        {
            if((mid * a[i]) > b[i])
            {
                extra += ((mid * a[i]) - b[i]);
            }
        }
        if(extra <= k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    extra = 0;
    rep(i,0,n)
    {
        if((low*a[i]) > b[i])
        {
            extra += (((low * a[i]) - b[i]));
        }
    }
    if(extra > k)
    {
        --low;
    }
    cout<<low;
	return 0;
}
