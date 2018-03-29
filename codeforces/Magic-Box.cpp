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
	ll ans = 0, x, y, z, x1, y1, z1, a1, a2, a3, a4, a5, a6;
	cin >> x >> y >> z;
	cin >> x1 >> y1 >> z1;
	cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
	if(x < 0)
	{
		ans += a5;
	}
	if(x > x1)
	{
		ans += a6;
	}
	if(y < 0)
	{
		ans += a1;
	}
	if(y > y1)
	{
		ans += a2;
	}
	if(z < 0)
	{
		ans += a3;
	}
	if(z > z1)
	{
		ans += a4;
	}
	cout << ans;
	return 0;
}