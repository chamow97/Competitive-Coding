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
    ll n, m, k;
    cin>>n>>m>>k;
    vector<ll> arr(n+1);
    rep(i,1,n+1)
    {
        cin>>arr[i];
    }
    ll pos = -1, i, j;
    for(i = m + 1; i <= n; i++)
    {
        if(arr[i] != 0 && arr[i] <= k)
        {
            pos = i;
            break;
        }
    }
    ll minimum = 1000000000;
    if(pos != -1)
    minimum = min(minimum, 10*(pos - m));
    pos = -1;
    for(j = m-1; j>0; j--)
    {
        if(arr[j] != 0 && arr[j] <= k)
        {
            pos = j;
            break;
        }
    }
    if(pos != -1)
    minimum = min(minimum, (m - pos) * 10);
    cout<<minimum;
	return 0;
}
