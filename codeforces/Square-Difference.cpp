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

const ll MAXN = 1e6;
boolean isPrime(MAXN, true);

void prime()
{
	isPrime[1] = isPrime[0] = false;
	for(ll i = 2; i <= sqrt(MAXN); i++)
	{
		if(isPrime[i])
		{
			for(ll j = 2 * i; j < MAXN; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}

int main()
{
	fastread;
	ll t;
	cin >> t;
	while(t--)
	{
		ll a, b;
		cin >> a >> b;
		ll rem = a - b;
		ll area1 = (rem);
		ll area2 = (a + b);
		if(area1 == 0)
		{
			cout << "NO";
		}
		else if(area1 == 1 && area2 == 1)
		{
			cout << "NO";
		}
		else if(area1 == 1 && area2 == 2)
		{
			cout << "YES";
		}
		else if(area1 % 2 == 0 || area2 % 2 == 0)
		{
			cout << "NO";
		}
		else if(area1 == 1)
		{
			bool isPrime = true;
			for(ll i = 2; i <= sqrt(area2); i++)
			{
				if(area2 % i == 0)
				{
					isPrime = false;
					break;
				}
			}
			if(isPrime)
			{
				cout << "YES";
			}
			else
			{
				cout << "NO";
			}
		}
		else
		{
			cout << "NO";
		}
		cout << '\n';
	}
	return 0;
}