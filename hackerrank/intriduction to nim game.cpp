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
    ll g,n;
    vector<ll> arr(101);
    cin>>g;
    while(g--)
    {
        cin>>n;
        ll ans=0;
        rep(i,0,n)
        {
            cin>>arr[i];
            ans = ans ^ arr[i];
        }
        if(ans == 0)
        {
            cout<<"First\n";
        }
        else
        {
            cout<<"Second\n";
        }
    }
	return 0;
}
