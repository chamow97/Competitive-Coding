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
	//very tough for me
	//good problem though
	fastread;
	ll n, x, k;
	cin >> n >> x >> k;
	vec arr(n,0);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	ll ans = 0;
	sort(arr.begin(), arr.end());
	rep(i,0,n)
	{
		ll extra;
		if(arr[i] % x == 0)
		{
			extra = 1;
		}
		else
		{
			extra = 0;
		}
		ll val = x * (arr[i]/x + k - extra);
		ll val1 = x * ((arr[i]/x) + k - extra + 1);
		ll ptr1 = lower_bound(arr.begin(), arr.end(), val) - arr.begin();
		ll ptr2 = lower_bound(arr.begin(), arr.end(), val1) - arr.begin();
		if(arr[i] != arr[ptr1])
		{
			ll ptr3 = lower_bound(arr.begin(), arr.end(), arr[i]) - arr.begin();
			ptr1 = max(ptr1, ptr3);
		}
		--ptr2;
		if(ptr1 == n)
		{
			break;
		}
		ans += (max(0ll, ptr2 - ptr1 + 1));
	}
	cout << ans;
	return 0;
}
