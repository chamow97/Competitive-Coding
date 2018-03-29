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
#define vecit vector<ll> :: iterator
#define vecpit vector< pair<ll, ll> > :: iterator
#define f first
#define s second


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;
typedef vector< pair<ll, ll> > vecpair;


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
	ll n, u;
	cin >> n >> u;
	vec arr(n, 0);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	double ans = 0.0;
	bool isFound = false;
	rep(i,0,n)
	{
		ll pos = upper_bound(arr.begin(), arr.end(), arr[i] + u) - arr.begin();
		--pos;
		if(arr[pos] != arr[i] && arr[pos-1] != arr[i])
		{
			ll k = arr[pos];
			ll j = arr[i+1];
			ll iVal = arr[i];
			double now = (k - j) * 1.00;
			now /= (k - iVal) * 1.00;
			ans = max(ans, now);
			isFound = true;
		}	
		else
		{
			continue;
		}
	}
	if(!isFound)
	{
		ans = -1;
	}
	cout << setprecision(15) << ans;
	return 0;
}