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
    ll t;
    cin>>t;
    while(t--)
    {
        ll ans = 0;
        ll ones = 0, nextpos = -1, current = -1;
        string str;
        cin>>str;
        ll len = str.length();
        ll i = 0;
        while(str[i] == '0')
        {
            i++;
        }
        ones ++;
        current = i;
        i++;

        rep(j,i,len)
        {
            if(str[j] == '1')
            {
                ++ones;
                current = j;
            }
            else
            {
                ll l = j;
                while(str[l] == '0' && l < len)
                {
                    l++;
                }
                j = l-1;
                ans += ((l - current) * (ones));
            }
        }
        cout<<ans<<endl;

    }
	return 0;
}
