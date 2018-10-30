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
	ll n, l, a;
	cin >> n >> l >> a;
	if(n == 0)
	{
		cout << l / a;
		return 0;
	}
	vecpair p(n);
	ll breaks = 0;
	rep(i,0,n)
	{
		cin >> p[i].f >> p[i].s;
	}
	breaks += ((p[0].f) / a);
	rep(i,1,n)
	{
		breaks += ((p[i].f - (p[i-1].s + p[i - 1].f)) / a);
	}
	breaks += ((l - (p[n - 1].s + p[n-1].f)) / a);
	cout << breaks;
	return 0;
}