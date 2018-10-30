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
	ll n, k;
	cin >> n >> k;
	map<ll, ll> left, right;
	vec arr(n, 0);
	rep(i,0,n)
	{
		cin >> arr[i];
		right[arr[i]]++;
	}
	ll ans = 0;
	rep(i,0,n)
	{
		ll curr = arr[i];
		ll k1 = 0, k2 = 0;
		if(curr % k == 0)
		{
			k1 = left[curr / k];
		}
		right[curr]--;
		k2 = right[curr * k];
		ans += (k1 * k2);
		left[curr]++;
	}
	cout << ans;
	return 0;
}