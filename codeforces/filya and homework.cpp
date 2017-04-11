
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
    ll n, temp;
    cin>>n;
    set<ll> s;
    rep(i,0,n)
    {
        cin>>temp;
        s.insert(temp);
    }
    if(s.size() > 3)
    {
        cout<<"NO";
        return 0;
    }
    set<ll>::iterator i;
    ll k = 0;
    vector<ll> arr(3);
    if(s.size() == 3)
    {
        for(i = s.begin(); i != s.end(); i++)
    {
        arr[k++] = *i;
    }
    if(arr[1] - arr[0] != arr[2] - arr[1])
    {
        cout<<"NO";
        return 0;
    }

    }

    cout<<"YES";
	return 0;
}
