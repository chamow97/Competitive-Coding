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
    ll n;
    ll counter = 0, minsofar = 1000000000;
    cin>>n;;
    vector<ll> arr(n);

    rep(i,0,n)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    counter = 1;
    minsofar = arr[1] - arr[0];
    rep(i,2,n)
    {
        if(arr[i] - arr[i-1] == minsofar)
        {
            ++counter;
        }
        else if(arr[i] - arr[i-1] < minsofar)
        {
            minsofar = arr[i] - arr[i-1];
            counter = 1;
        }
    }
    cout<<minsofar<<" "<<counter;
	return 0;
}
