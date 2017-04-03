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

bool myFunc1(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.first < b.first;
}
bool myFunc2(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}

int main()
{
    ll n,m,ans = 0;
    cin>>n;
    pair<ll, ll> a[n];
    rep(i,0,n)
    {
        cin>>a[i].first>>a[i].second;
    }
    cin>>m;
    pair<ll, ll> b[m];

    rep(i,0,m)
    {
        cin>>b[i].first>>b[i].second;
    }
    sort(a, a+n, myFunc1);
    sort(b, b+m, myFunc2);
    ans = max(ans, (a[n-1].first - b[0].second));
    //cout<<ans<<" ";
    sort(a, a+n, myFunc2);
    sort(b, b+m, myFunc1);
    ans = max(ans, (b[m-1].first - a[0].second));
    cout<<ans;
	return 0;
}
