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
	ll n, a, b, c;
	cin>>n>>a>>b>>c;
	--n;
	ll ans = 0;
	ll current = 1;
	while(n--)
	{
		if(current == 1)
		{
			if(a < b)
			{
				current = 2;
				ans += a;
			}
			else
			{
				current = 3;
				ans += b;
			}
		}
		else if(current == 2)
		{
			if(a < c)
			{
				current = 1;
				ans += a;
			}
			else
			{
				current = 3;
				ans += c;
			}
		}
		else if(current == 3)
		{
			if(b < c)
			{
				current = 1;
				ans += b;
			}
			else
			{
				current = 2;
				ans += c;
			}
		}

	}
	cout<<ans;
	return 0;
}
