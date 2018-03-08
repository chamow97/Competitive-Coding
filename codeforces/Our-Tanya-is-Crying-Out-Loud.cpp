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
	ll n, k, a, b;
	cin >> n >> k >> a >> b;
	if(k == 1)
	{
		cout << a * (n - 1);
		return 0;
	}
	//remove extras
	ll sum = 0;
	while(n > 1)
	{
		ll extra = n % k;
		sum += (a * extra);
		n -= (n % k);
		if(n == 0)
		{
			++n;
			sum -= a;
		}
		if(n == 1)
		{
			break;
		}
		ll temp = n / k;
		if(b <= (a * (n - temp)))
		{
			n /= k;
			sum += b;
		}
		else
		{
			sum += (a * (n - temp));
			n /= k;
		}
	}
	cout << sum;
	return 0;
}