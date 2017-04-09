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
    ll t, n, k;
    cin>>t;
    rep(i,0,t)
    {
        ll power = 0, temp, ans;
        cin>>n>>k;
        power = log2(k);
        while(power >= 0)
        {
            n /= 2;
            --power;
        }
        cout<<n<<endl;
    }
	return 0;
}
