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
	ll n, m;
	cin >> n >> m;
	if(m == 0)
	{
		cout << n << ' ' << n;
		return 0;
	}
	if(n == 1)
	{
		cout << 1 << ' ' << 1;
		return 0;
	}
	if(n == 2)
	{
		cout << 0 << ' ' << 0;
		return 0;
	}
	//min
	ll minimum = 0;
	minimum = n - (m * 2);
	// maximum
	minimum = max(minimum, 0ll);
	ll maximum = 0;

	if(m < 3)
	{
		maximum = n - m - 1;
	}
	else
	{	
		ll needed = 1;
		ll now = 1;
		while(m > 0)
		{
			m -= now;
			needed++;
			now++;
		}	
		maximum = n - needed;
	}
	cout << minimum << ' ' << maximum;
	return 0;
}