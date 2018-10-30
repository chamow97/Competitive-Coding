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

const ll MAXN = 1e6 + 400;

int main()
{
	fastread;
	ll n;
	cin >> n;
	if(n == 1 || n == 2)
	{
		cout << n;
		return 0;
	}
	else if(n == 3)
	{
		cout << 6;
		return 0;
	}
	else 
	{
		ll ans = 0;
		for(ll x = n - 50; x <= n; x++)
		{
			for(ll y = n - 50; y <= n; y++)
			{
				for(ll z = n - 50; z <= n; z++)
				{
					if(x < 1 || y < 1 || z < 1)
					{
						continue;
					}
					ll now = x / __gcd(x, y) * y;
					now = now / __gcd(now, z) * z;
					ans = max(ans, now);
				}
			}
		}
		cout << ans;
	}
	return 0;
}