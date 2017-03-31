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
typedef vector<ll> array;
typedef vector<bool> boolean;

/*-------------------------------------------------------- */

int main()
{
    ll t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n%2 == 0 || m == 1)
        {
            cout<<2<<endl;
        }
        else
        {
            cout<<1<<endl;
        }
    }
	return 0;
}
