//template by chamow
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

int main()
{
	fastread;
    ll n;
    cin>>n;
    vec arr(n,0);
    vec brr(n,0);
    rep(i,0,n)
    {
        cin>>arr[i];
        brr[i] = arr[i];
    }
    sort(brr.begin(), brr.end());
    ll ans = 0;
    rep(i,0,n)
    {
        ll pos = lower_bound(brr.begin(), brr.end(), arr[i]) - brr.begin();

    }
    cout<<ans;
	return 0;
}
