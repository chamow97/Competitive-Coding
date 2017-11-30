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
	ll n, s;
	cin >> n >> s;
	ll maximum = -1;
	rep(i,0,n)
	{
		ll x1, y1;
		cin >> x1 >> y1;
		if(x1 < s)
		{
			if(y1 == 0)
			{
				maximum = max(maximum, 0ll);
			}
			else
			{
				maximum = max(maximum, 100 - y1);
			}
		}
		else if(x1 == s && y1 == 0)
		{
			maximum = max(maximum, 0ll);
		}
	}
	cout << maximum;
	return 0;
}
