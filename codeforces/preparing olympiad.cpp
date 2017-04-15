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
    ll n, y, l, r, counter = 0;
    cin>>n>>l>>r>>y;
    vector<ll> arr(n,0);
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    rep(i,1,pow(2,n))
    {
        bool isOkay = true;
        vector<ll> temp;
        string x = "";
        ll temp1 = i;
        while(temp1)
        {
            ll t = temp1 % 2;
            temp1 /= 2;
            x = char(t + 48) + x;
        }
//        cout<<x<<endl;
        ll pos = n-1;
        per(j,x.length()-1,0)
        {
            if(x[j] == '1')
            {
                temp.pb(arr[pos]);
//                cout<<arr[pos]<<" ";
            }
            --pos;
        }
//        cout<<endl;
        sort(temp.begin(), temp.end());
        ll sum = 0;
//        rep(k,0,temp.size())
//        {
//            cout<<temp[k]<<" ";
//        }
//        cout<<endl;
        if(temp.size() > 1)
        {
            if(temp[temp.size()-1] - temp[0] >= y)
            {
                rep(k,0,temp.size())
                {
                    sum += temp[k];
                }
            }
            else
            {
                isOkay = false;
            }
//            cout<<endl;

        if(sum < l || sum > r)
        {
            isOkay = false;
        }
        if(isOkay == true)
        {
            ++counter;
        }
        }

    }
    cout<<counter;

	return 0;
}
