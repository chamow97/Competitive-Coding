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
    ll n,k,ans = 0;
    cin>>n>>k;
    vector<ll> arr(n);
    rep(i,0,n)
    {
        cin>>arr[i];
        ans += (arr[i]/k);
        if(arr[i] % k != 0)
        {
            ans++;
        }
    }
    ans = (ans+1) / 2;
	cout<<ans;
	return 0;
}
