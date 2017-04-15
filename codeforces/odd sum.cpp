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
    cin>>n;
    vector<ll> arr(n,0);
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    ll sum = 0;
    ll minpositiveodd = 100000, maxnegativeodd = -100000;
    rep(i,0,n)
    {

        if(arr[i] >= 0)
        {
            if(arr[i] % 2 != 0)
            {
                minpositiveodd = min(minpositiveodd, arr[i]);
            }
            sum += arr[i];
        }
        if(arr[i] < 0)
        {
            if(arr[i] % 2 != 0)
            {
                maxnegativeodd = max(maxnegativeodd, arr[i]);
            }
        }
    }
    if(sum % 2 == 1)
    {
        cout<<sum;
        return 0;
    }
    if(minpositiveodd == 100000)
    {
        sum += maxnegativeodd;
    }
    else if(maxnegativeodd == -100000)
    {
        sum = sum - minpositiveodd;
    }
    else
    {
        sum = max(sum - minpositiveodd, sum + maxnegativeodd);
    }
    cout<<sum;
    return 0;
}
