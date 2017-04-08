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
vector<ll> ans;
void func(ll n)
{
    ll t = n;
    ll val = 0;
    if(n <= 0)
    {
        return;
    }
    vector<ll> temp;
    while(n)
    {
        temp.pb(n % 10);
        n /= 10;
    }
    per(j,temp.size()-1,0)
    {
        if(temp[j] == 0)
        {
            val = (val * 10);
        }
        else
        {
            val = (val * 10) + 1;
        }
    }
    ans.pb(val);
    func(t-val);
}

int main()
{
    ll n;
    cin>>n;
    func(n);
    cout<<ans.size()<<endl;
    rep(i,0,ans.size())
    {
        cout<<ans[i]<<" ";
    }
	return 0;
}
