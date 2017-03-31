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
    ll t,n,k,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>m;
        ll ans = (min(k,m))+(n -max(k,m));
        cout<<ans<<endl;
    }
	return 0;
}
