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
	vec arr(n,0);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	rep(i,0,n)
	{
		ll j = 0;
		for(j = i; j < n; j++)
		{
			if(arr[i] != arr[j])
			{
				break;
			}
		}
		ll now = (j - i) * n;
		// cout << j << ' ' << i << ' ' << now << '\n';
		if(k > now)
		{
			k -= now;
			i = (j-1);
			continue;
		}
		rep(l,0,n)
		{
			ll right = (j - i);
			if(k <= right)
			{
				cout << arr[i] << ' ' << arr[l];
				return 0;	
			}
			k -= right;
		}
		i = (j-1);
	}
	return 0;
}
