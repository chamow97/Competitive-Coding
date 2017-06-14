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
    ll l = 0, h = 0;
    ll t, n;
    cin>>t;
    while(t--)
    {
        l = 0, h = 0;
        cin>>n;
        vec arr(n,0);
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        rep(i,1,n)
        {
            ll prevLow = l;
            l = max(l, h + (arr[i-1] - 1));
            h = max(prevLow + arr[i] - 1, h + abs(arr[i] - arr[i-1]));
        }
        cout<<max(l,h)<<'\n';
    }
	return 0;
}
