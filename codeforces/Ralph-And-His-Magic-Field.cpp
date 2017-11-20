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

ll power(ll a, ll b)
{
	ll res = 1, val = a;
	while(b)
	{
		if(b % 2 == 1)
		{
			res *= val;
			res %= MODULO;
		}
		val *= val;
		val %= MODULO;
		b /= 2;
	}
	return res;
}

int main()
{
	fastread;
	ll n, m, k;
	cin>>n>>m>>k;
	if(n > m)
	{
		swap(n,m);
	}
	if(k == -1 && (n + m) % 2 == 1)
	{
		cout<<0;
	}
	else if(n == 1)
	{
		cout<<1;
	}
	else
	{
		cout<<power(power(2,n-1), m-1);
	}
	return 0;
}
