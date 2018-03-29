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
	ll hh, mm, h, d, c, n;
	cin >> hh >> mm;
	cin >> h >> d >> c >> n;
	double minimum = INF;
	rep(i,hh,24)
	{
		rep(j,0,60)
		{
			if(i == hh && j < mm)
			{
				continue;
			}
			ll total = (i - hh) * 60 + (j - mm);
			ll totalHunger = h + (d * total);
			double bunCost = c * 1.00;
			if(i >= 20)
			{
				bunCost = (bunCost - (bunCost * 0.2));
			}
			ll needed = ceil(totalHunger * 1.00 / n);
			minimum = min(minimum, bunCost * needed * 1.00);
		}
	}
	cout << setprecision(15) << minimum;
	return 0;
}