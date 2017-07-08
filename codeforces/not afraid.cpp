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
    ll n,m,k;
    vector<ll> arr(100000);
    cin>>n>>m;
    bool isPossible = false;
    while(m--)
    {
        ll positive = 0;
        ll negative = 0;
        cin>>k;
        rep(i,0,k)
        {
            cin>>arr[i];
            if(arr[i] < 0)
            {
                ++negative;
            }
            else
            {
                ++positive;
            }
        }
        if(negative == k || positive == k)
        {
            isPossible = true;
        }
    }
    if(isPossible == true)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
	return 0;
}
