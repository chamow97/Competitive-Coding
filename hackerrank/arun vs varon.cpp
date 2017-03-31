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

bool check(ll p, ll q, ll a, ll b)
{

        if((p-a) == (q-b))
        {
            return true;
        }
        else
        {
            return false;
        }

}

int main()
{
    ll t, a, b, p, q;
    cin>>t;
    while(t--)
    {
        ll ans = 10000000000;
        ll multiply = 0, add = 0;
        cin>>a>>b>>p>>q;
        if(p&1 && q&1)
        {
            add++;
            if(p-1 >= a && q-1 >= b)
            {
                p -= 1;
                q -= 1;
            }

            if(check(p,q,a,b) == true)
            {
                ans = min(ans, multiply + (p-a) + add);
            }
        }
        else if( !(p&1) && !(q&1))
        {
            multiply++;
            if(p/2 >= a && q/2 >= b)
            {
                p /= 2;
                q /= 2;
            }
            p /= 2;
            q /= 2;
            if(check(p,q,a,b) == true)
            {
                ans = min(ans, multiply + (p-a) + add);
            }
        }
        else
        {
            if(check(p,q,a,b) == true)
            {
                ans = min(ans,(multiply + (p-a) + add));
            }
            else
            {
                cout<<"-1"<<endl;
                continue;
            }

        }
        cout<<ans<<endl;
    }
	return 0;
}
