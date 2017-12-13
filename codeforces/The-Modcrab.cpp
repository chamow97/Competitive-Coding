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
	ll h1, a1, c1, h2, a2;
	cin >> h1 >> a1 >> c1;
	cin >> h2 >> a2;
	vector<string> v, v1;
	while(h2 > 0 && h1 > 0)
	{
		if(h1 > a2)
		{
			h2 -= a1;
			v.pb("STRIKE");
		}
		else
		{
			if(h2 <= a1)
			{
				h2 -= a1;
				v.pb("STRIKE");
			}
			else
			{
				h1 += c1;
				v.pb("HEAL");	
			}
		}
		h1 -= a2;
	}
	cout << v.size() << '\n';
	rep(i,0,v.size())
	{
		cout << v[i] << '\n';
	}
	
	return 0;
}
