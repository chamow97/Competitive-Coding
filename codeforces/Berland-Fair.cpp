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
	ll n, t;
	cin >> n >> t;
	vec arr(n);
	ll minimum = INF;
	rep(i,0,n)
	{
		cin >> arr[i];
		minimum = min(minimum, arr[i]);
	}
	ll ans = 0;
	while(t >= minimum)
	{
		ll need = 0, curr = 0;
		ll left = t;
		rep(j,0,n)
		{
			if(arr[j] <= left)
			{
				need += arr[j];
				++curr;
				left -= arr[j];
			}
		}
		ll current = t / need;
		ans += (curr * current);
		t -= (need * current);
	}
	cout << ans;
	return 0;
}