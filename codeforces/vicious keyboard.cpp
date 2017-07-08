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
    string s;
    cin>>s;
    ll counter1 = 0, counter2 = 0, maximum = 0;
    ll len = s.length();
    rep(i,1,len)
    {
        if(s[i] == 'K' && s[i-1] == 'V')
        {
            ++counter1;
        }
    }
    rep(i,0,len)
    {
        string v = s;
        counter2 = 0;
        if(v[i] == 'V')
        {
            v[i] = 'K';
        }
        else
        {
            v[i] = 'V';
        }
        rep(j,1,len)
        {
            if(v[j] == 'K' && v[j-1] == 'V')
            {
                ++counter2;
            }
        }
        maximum = max(maximum, counter2);
    }
    ll ans = max(counter1, maximum);
    cout<<ans;
	return 0;
}
