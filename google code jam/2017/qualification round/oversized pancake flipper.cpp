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
    rep(l,0,t)
    {
        string str;
        ll width;
        ll counter = 0;
        cin>>str;
        ll len = str.length();
        cin>>width;
        ll i = 0;
        ll j = width-1;
        while(j<len)
        {
            if(str[i] == '-')
            {
                ++counter;
                rep(m,i,i+width)
                {
                    if(str[m] == '+')
                    {
                        str[m] = '-';
                    }
                    else
                    {
                        str[m] = '+';
                    }
                }
            }
            ++i;
            ++j;
        }
        bool isCorrect = true;
        rep(i,0,len)
        {
            if(str[i] == '-')
            {
                isCorrect = false;
                break;
            }
        }
        cout<<"Case #"<<l+1<<": ";
        if(isCorrect == false)
        {
            cout<<"IMPOSSIBLE\n";
        }
        else
        {
            cout<<counter<<endl;
        }
    }
	return 0;
}
