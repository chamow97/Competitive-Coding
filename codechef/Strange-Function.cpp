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
	#define MOD 9
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
	ll power(ll base, ll exp) {
	    ll res=1;
	    while(exp>0) {
	       if(exp%2==1) res=(res*base)%MOD;
	       base=(base*base)%MOD;
	       exp/=2;
	    }
	    return res;
	}


	void solve()
	{
		ll a, d;
		cin >> a >> d;
		a %= MOD;
		ll val = power(a, d) % 9;
		if(val == 0)
		{
			cout << 9;
		}
		else
		{
			cout << val;
		}
	}

	int main()
	{
		fastread;
		ll t;
		cin >> t;
		while(t--)
		{
			solve();
			cout << '\n';
		}
		return 0;
	}
