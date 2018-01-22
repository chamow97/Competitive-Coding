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
#define INF 1000000000
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

const ll maxn = 1e5 + 500;

boolean primeNumbers(maxn, true);
vec prime;

void seive()
{
	rep(i,2,maxn)
	{
		if(primeNumbers[i])
		{
			prime.pb(i);
			for(ll j = i; j < maxn; j += i)
			{
				primeNumbers[j] = false;
			}

		}
	}
}

int main()
{
	fastread;
	ll n, m;
	seive();
	cin >> n >> m;
	ll pos = *lower_bound(prime.begin(), prime.end(), n - 1);
	cout << pos << ' ' << pos <<'\n';
	rep(i,1,n - 1)
	{
		cout << i << ' ' << i + 1 << ' ' << 1 << '\n';
		--pos;
	}
	cout << n - 1 << ' ' << n << ' ' << pos << '\n';
	m -= (n - 1);
	ll ptr1 = 1, ptr2 = 1 + ptr1;
	while(m > 0)
	{
		if(ptr1 == ptr2 || ptr2 == (ptr1 + 1))
		{
			++ptr2;
			if(ptr2 > n)
			{
				ptr1++;
				ptr2 = ptr1 + 1;
			}
			continue;
		}
		cout << ptr1 << ' ' << ptr2 << ' ' << INF << '\n';
		++ptr2;
		if(ptr2 > n)
		{
			ptr1++;
			ptr2 = ptr1 + 1;
		}
		--m;
	}
	return 0;
}
