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

ll gcd(ll a, ll b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b,a%b);
}

int main()
{
    ll n, temp, hcf;
    cin>>n;
    vector<ll> arr(n);
    rep(i,0,n)
    {
        cin>>arr[i];
        if(i>1)
        {
            hcf = gcd(hcf, arr[i]);
        }
        if(i == 1)
        {
            hcf = gcd(arr[1], arr[0]);
        }
    }
    while(hcf % 2 == 0)
    {
        hcf /= 2;
    }
    while(hcf % 3 == 0)
    {
        hcf /= 3;
    }
    rep(i,0,n)
    {
        ll two = 1, three = 1;
        while(arr[i] % (two * 2) == 0)
        {
            two *= 2;
        }
        while(arr[i] % (three * 3) == 0)
        {
            three *= 3;
        }
        if((two * three * hcf) != arr[i])
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}