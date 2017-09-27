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
boolean prime(1e5+10, true);
vec primeNumbers;
void seive()
{
	rep(i,2,sqrt(1e5)+10)
	{
		if(prime[i])
		{
			for(ll j = i*2; j <= 1e5 + 10; j += i)
			{
				prime[j] = false;
			}
		}

	}
	rep(i,2,1e5+10)
	{
		if(prime[i])
		{
			primeNumbers.pb(i);
		}
	}
}
ll lpf(ll n)
{
	bool found = true;
	ll temp = n;
	ll maxi = 0;
	if(n % 2 == 0)
	{
		maxi = max(maxi, 2ll);
		while(n % 2 == 0)
		{
			n /= 2;
		}
	}
	for(ll i = 3; i <= sqrt(temp); i += 2)
	{
		if(n % i == 0)
		{
			maxi = max(maxi, i);
			while(n % i == 0)
			{
				n /= i;
			}
		}
	}
	if(n > 2)
	{
		maxi = max(maxi, n);
	}
	return maxi;
}

int main()
{
	fastread;
	ll t;
	cin>>t;
	seive();
	while(t--)
	{
		ll n;
		cin>>n;
		ll largestPrimeFactor;
		if(prime[n])
		{
			largestPrimeFactor = n;
		}
		else
		{
			largestPrimeFactor = lpf(n);
		}
		
		// cout<<largestPrimeFactor<<" ";
		cout<<*upper_bound(primeNumbers.begin(), primeNumbers.end(), largestPrimeFactor)<<'\n';
	}
	return 0;
}
