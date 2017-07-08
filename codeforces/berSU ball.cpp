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
    ll n, m;
    cin>>n;
    vector<ll> a(n,0);
    rep(i,0,n)
    {
        cin>>a[i];
    }
    cin>>m;
    vector<ll> b(m,0);
    rep(i,0,m)
    {
        cin>>b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll i = 0, j = 0, counter = 0;
    while(i<n && j<m)
    {
        if(abs(a[i] - b[j]) <= 1)
        {
            ++counter;
            ++i;
            ++j;
        }
        else if(a[i] < b[j])
        {
            i++;
        }
        else if(b[j] < a[i])
        {
            j++;
        }
    }
    cout<<counter;

	return 0;
}
