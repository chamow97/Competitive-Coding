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
    string number;
    cin>>number;
    number = "00" + number;
    ll length = number.length();
    rep(i,0,length)
    {
        rep(j,i+1,length)
        {
            rep(k,j+1,length)
            {
                ll temp = (((number[i] - '0')*100) + ((number[j] - '0')*10) + ((number[k] - '0')));
                if(temp % 8 == 0)
                {
                    cout<<"YES"<<endl<<temp;
                    return 0;
                }
            }
        }
    }
    cout<<"NO";

	return 0;
}
