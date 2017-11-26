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
	map<ll, ll> m;
	rep(i,0,11)
	{
		ll ans = 0;
		rep(j,0,i+1)
		{
			ans += (pow(2, j + i));
		}
		m[ans]++;
	}
	ll n;
	cin >> n;
	set<ll> divisors;
	rep(i,1,sqrt(n)+1)
	{
		if(n % i == 0)
		{
			divisors.insert(i);
			divisors.insert(n/i);
		}
	}
	ll ans = 0;
	for(auto i : divisors)
	{
		if(m[i] == 1)
		{
			ans = i;
		}
	}
	cout << ans;

	return 0;
}
