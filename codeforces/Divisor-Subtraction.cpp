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

boolean isPrime(1000001, true);

void findPrime()
{
	rep(i,2,sqrt(1000001) + 1)
	{
		if(isPrime[i])
		{
			for(int j = 2 * i; j <= 1000000; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}

int main()
{
	fastread;
	ll n;
	cin >> n;
	if(n % 2 == 0)
	{
		cout << n / 2;
	}
	else
	{
		ll ptr = -1;
		rep(i,2,sqrt(n) + 1)
		{
			if(isPrime[i] && (n % i) == 0)
			{
				ptr = i;
				break;
			}
		}
		if(ptr == -1)
		{
			cout << 1;
		}
		else
		{
			cout << 1 + (n - ptr) / 2;
		}
	}
	return 0;
}