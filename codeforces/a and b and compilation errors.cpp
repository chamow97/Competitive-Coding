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
    vector<ll> a(n), b(n-1), c(n-2);
    rep(i,0,n)
    {
        cin>>a[i];
    }
    rep(i,0,n-1)
    {
        cin>>b[i];
    }
    rep(i,0,n-2)
    {
        cin>>c[i];
    }
    sort(a.begin(), a.end());

    sort(b.begin(), b.end());

    sort(c.begin(), c.end());
    bool isFound = false;
    rep(i,0,n-1)
    {
        if(a[i] != b[i])
        {
            isFound = true;
            cout<<a[i]<<" ";
            break;
        }
    }
    if(isFound == false)
    {
        cout<<a[n-1]<<" ";
    }
    cout<<endl;
    isFound = false;
    rep(i,0,n-2)
    {
        if(b[i] != c[i])
        {
            isFound = true;
            cout<<b[i];
            break;
        }
    }
    if(isFound == false)
    {
        cout<<b[n-2]<<" ";
    }

	return 0;
}
