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
	ll n, one, two, half = 0;
	cin >> n >> one >> two;
	ll ans = 0;
	rep(i,0,n)
	{
		ll val;
		cin >> val;
		if(val == 1)
		{
			if(one > 0)
			{
				one--;
			}
			else if(two > 0)
			{
				two--;
				half++;
			}
			else if(half > 0)
			{
				half--;
			}
			else
			{
				ans++;
			}
		}
		else
		{
			if(two > 0)
			{
				two--;
			}
			else
			{
				ans += 2;
			}
		}
	}
	cout << ans;
	return 0;
}