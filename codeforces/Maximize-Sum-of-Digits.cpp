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

ll getSum(ll n)
{
	ll currSum = 0;
	while(n)
	{
		currSum += (n % 10);
		n /= 10;
	}
	return currSum;
}

int main()
{
	fastread;
	ll n;
	cin >> n;
	ll maximum = getSum(n);
	ll maxVal = n;
	ll nine = 9, ten = 10;
	while(nine < n)
	{
		ll now = (n/ten - 1)*ten + nine;
		if(getSum(now) > maximum)
		{
			maximum = getSum(now);
			maxVal = now;
		}
		nine = (nine * 10) + 9;
		ten *= 10;
	}
	cout << maxVal;

	return 0;
}
