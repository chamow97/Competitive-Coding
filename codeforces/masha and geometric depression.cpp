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
    ll a,r,maxi,n;
    cin>>a>>r>>maxi>>n;
    vector<ll> arr(n), ans;
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    if(abs(a) > maxi)
    {
        cout<<"0\n";
    }
    else if(a == 0)
    {
        if(*lower_bound(arr.begin(), arr.end(), 0) == 0)
        {
            cout<<"0\n";
        }
        else
        {
            cout<<"inf\n";
        }
    }
    else if(r == 1)
    {
        if(*lower_bound(arr.begin(), arr.end(), a) == a)
        {
            cout<<"0\n";
        }
        else
        {
            cout<<"inf\n";
        }
    }
    else if(r == -1)
    {
        if(*lower_bound(arr.begin(), arr.end(), a) == a && *lower_bound(arr.begin(), arr.end(), -a) == -a)
        {
            cout<<"0\n";
        }
        else
        {
            cout<<"inf\n";
        }
    }
    else if(r == 0)
    {
        if(*lower_bound(arr.begin(), arr.end(), 0) != 0)
        {
            cout<<"inf\n";
        }
        else if(*lower_bound(arr.begin(), arr.end(), a) == a)
        {
            cout<<"0\n";
        }
        else
        {
            cout<<"1\n";
        }
    }
    else
    {
        ll temp = a;
        while(abs(temp) <= maxi)
        {
            ans.pb(temp);
            temp *= (r);
        }
        sort(ans.begin(), ans.end());
        ll result = ans.size();
        rep(i,0,n)
        {
            if(*lower_bound(ans.begin(), ans.end(), arr[i]) == arr[i])
            {
                --result;
            }
        }
        cout<<result<<endl;
    }

	return 0;
}
