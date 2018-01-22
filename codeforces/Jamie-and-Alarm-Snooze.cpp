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

ll counter = 0;
bool findSeven(ll n)
{
	while(n)
	{
		if(n % 10 == 7)
		{
			return true;
		}
		n /= 10;
	}
	return false;
}

int main()
{
	fastread;
	ll x, h, m;
	cin >> x >> h >> m;
	while(1)
	{
		if(findSeven(h) == true || findSeven(m) == true)
		{ 	
			break;
		}
		++counter;
		m -= x;
		if(m < 0)
		{
			m = 60 + m;
			--h;
		}
		if(h < 0)
		{
			h = 24 + h;
		}
	}
	// cout << h << ":" << m << '\n';
	cout << counter;

	return 0;
}
