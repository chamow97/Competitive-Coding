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

ll sign(ll n)
{
    if(n % 2 == 0)
    {
        return 1;
    }
    return -1;
}

int main()
{
    ll n, maximum=0;
    cin>>n;
    vector<ll> arr(n+1);
    vector<ll> val(n);
    vector<ll> arr1(n), arr2(n);
    rep(i,1,n+1)
    {
        cin>>arr[i];
    }
    rep(i,1,n)
    {
        val[i] = abs(arr[i] - arr[i+1]);
        arr1[i] = val[i];
        arr2[i] = arr1[i];
        if(i%2 == 0)
        {
            arr1[i] = -arr1[i];
        }
        else
        {
            arr2[i] = -arr2[i];
        }
    }
     maximum = arr1[1];
    ll previous = arr1[1];
    rep(i,2,n)
    {
        maximum = max(maximum, previous + arr1[i]);
        previous += arr1[i];
        if(previous < 0)
        {
            previous = 0;
        } 
    }
    previous = 0;
    rep(i,2,n)
    {
        maximum = max(maximum, arr2[i]+previous);
        previous += arr2[i];
        
        if(previous < 0)
        {
            previous = 0;
        }
    }
    cout<<maximum;

        return 0;
}
