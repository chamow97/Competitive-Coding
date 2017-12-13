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

ll reverse(ll i)
{
	ll rev = 0;
	while(i)
	{
		rev = (rev * 10) + (i % 10);
		i /= 10;
	}
	return rev;
}

int main()
{
	fastread;
	ll k, p;
	cin >> k >> p;
	vec dp;
	// dp.pb(-1);
	ll ptr = 1;
	ll sum = 0;
	ll power = 0;
	while(k > 0)
	{
		ll start = pow(10,power);
		ll end = pow(10, power + 1);
		rep(i,start,end)
		{
			ll revNo = reverse(i);
			ll original = revNo + (i * (end));
			// dp.pb(original);
			sum = (sum + original) % p;
			--k;
			if(k <= 0)
			{
				break;
			}
		}
		++power;
	}
	cout << sum;
	return 0;
}
