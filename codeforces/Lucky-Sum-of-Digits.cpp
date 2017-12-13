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
	ll n;
	cin >> n;
	ll minimum = INF;
	ll a = 0, b = 0;
	rep(i,0,1e6)
	{
		ll val = n - (7 * i);
		if(val % 4 == 0 && val >= 0)
		{
			val /= 4;
			if(minimum > (val + i))
			{
				a = val;
				b = i;
				minimum = a + b;
			}
			else if(minimum == (val + i))
			{
				if(a < val)
				{
					a = val;
					b = i;
				}
			}
		}
	}
	if(a == 0 && b == 0)
	{
		cout << -1;
	}
	else
	{
		rep(i,0,a)
		{
			cout << 4;
		}
		rep(i,0,b)
		{
			cout << 7;
		}
	}


	return 0;
}
