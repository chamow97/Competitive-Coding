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

void solve()
{
	ll d;
	cin >> d;
	if(d == 0)
	{
		cout << "Y 0 0";
	}
	else if(d < 4)
	{
		cout << "N";
	} 
	else
	{
		long double root = ((d * d * 1.00) - (4 * 1 * d));
		root = sqrt(root);
		long double a = ((d + root) * (1.00)) / (2 * 1.00);
		long double b = ((d - root) * (1.00)) / (2 * 1.00);
		cout << "Y " << setprecision(15) << a << " " << b;
	}
	cout << '\n';
}

int main()
{
	fastread;
	ll t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}