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
    ll n,m, sum = 0;
    cin>>n>>m;
    vector<ll> arr(n,0);
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    rep(i,0,m)
    {
        if(arr[i] > 0)
        {
            break;
        }
        sum += arr[i];
    }
    cout<<(sum * (-1));
	return 0;
}
