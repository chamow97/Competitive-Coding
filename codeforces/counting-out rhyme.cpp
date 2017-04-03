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
typedef long long ll ;

/*-------------------------------------------------------- */


int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> a;
    ll arr[k+1];

    rep(i,1,n+1)
    {
        a.pb(i);
    }
    rep(i,1,k+1)
    {
        cin>>arr[i];
    }
    ll current = 1;
    rep(i,1,k+1)
    {
        current = (current + arr[i]);

        current = current % (a.size());
        if(current == 0)
        {
            current = a.size();
        }

        ll temp=0,val;
        vector<ll>::iterator it;
        for(it = a.begin(); it != a.end(); it++)
        {
            val = *it;
            ++temp;
            if(temp == current)
            {
                break;
            }
        }
        cout<<val<<" ";
        a.erase(remove(a.begin(), a.end(), val), a.end());
        current = lower_bound(a.begin(),a.end(),(val+1)%(n+1)) - a.begin();
        current++;
    }
    return 0;
}
