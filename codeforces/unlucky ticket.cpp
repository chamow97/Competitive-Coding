
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
    string s;
    cin>>s;
    sort(s.begin(), s.begin() + n);
    sort(s.begin() + n, s.end());
    bool flag = true, flag1 = true;
    rep(i,0,n)
    {
        if(s[i] < s[n+i])
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
    }
    if(flag == true)
    {
        cout<<"YES";
    }
    else
    {
        flag = true;
        rep(i,0,n)
        {
            if(s[i] <= s[n+i])
            {
                flag = false;
                break;
            }
        }
        if(flag == true)
        {
            cout<<"YES";
            return 0;
        }
        cout<<"NO";
    }
	return 0;
}
