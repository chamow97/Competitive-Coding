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
    string x,y;
    string z = "";
    cin>>x>>y;
    ll len = x.length();
    rep(i,0,len)
    {
        if(x[i] < y[i])
        {
            cout<<-1;
            return 0;
        }
        else if(x[i] == y[i])
        {
            if(x[i] == 'z')
            {
                z = z + char(x[i]);
            }
            else
            z = z + char(x[i] + 1);
        }
        else
        {
            z =  z + char(y[i]);
        }
    }
    cout<<z;
	return 0;
}
