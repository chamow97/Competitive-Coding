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

ll bsearrch(ll low, ll high, ll value)
{

    if(low >= high)
    {
        return low;
    }
    ll mid = (low + high)/2;
    if((mid)*(mid + 1)/2 >= value)
    {
        return bsearrch(low, mid, value);
    }
    else
    {
        return bsearrch(mid+1, high, value);
    }
}


int main()
{
    ll n,m;
    cin>>n>>m;
    if(n <= m)
    {
        cout<<n;
    }
    else
    {
        ll val = n - m;
        ll low = 1, high = 10000000000;
        cout<<bsearrch(low,high,val) + m;
    }
	return 0;
}
