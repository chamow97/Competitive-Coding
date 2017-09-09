
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;


/*-------------------------------------------------------- */

ll gcd(ll a, ll b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a,b));
}

/*-------------------------------------------------------- */

bool myFunc(ll a, ll b)
{
    return a > b;
}

int main()
{
	fastread;
    ll n;
    cin>>n;
    vec *thick_width = new vec[2];
    ll totalWidth = 0, totalThick = 0;
    rep(i,0,n)
    {
        ll t, w;
        cin>>t>>w;
        totalThick += t;
        totalWidth += w;
        if(t == 1)
        {
            thick_width[0].pb(w);
        }
        else
        {
            thick_width[1].pb(w);
        }
    }
    sort(thick_width[0].begin(), thick_width[0].end(), myFunc);
	sort(thick_width[1].begin(), thick_width[1].end(), myFunc);
	ll minimum = INF;
    rep(i,0,thick_width[0].size()+1)
    {
        rep(j,0,thick_width[1].size()+1)
        {
            ll currWidth = (i) + (2*j);
            ll value = 0;
            rep(k,i,thick_width[0].size())
            {
                value += thick_width[0][k];
            }
            rep(k,j,thick_width[1].size())
            {
                value += thick_width[1][k];
            }
            if(currWidth >= value)
            {
                minimum = min(minimum, currWidth);
            }
        }
    }
    cout<<minimum;
	return 0;
}
