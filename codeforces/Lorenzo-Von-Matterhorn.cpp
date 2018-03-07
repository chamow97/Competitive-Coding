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
map<ll, ll> m;

void solve(ll u, ll v, ll w)
{
	ll ans = 0;
	while(u != v)
	{
		if(u > v)
		{
			ans += m[u];
			m[u] += w;
			u /= 2;
		}
		else
		{
			ans += m[v];
			m[v] += w;
			v /= 2;
		}
	}
	if(w == 0)
	{
		cout << ans << '\n';
	}
}

int main()
{
	fastread;
	ll q;
	cin >> q;
	while(q--)
	{
		ll type, u, v, w = 0;
		cin >> type;
		if(type == 1)
		{
			cin >> u >> v >> w;
		}
		else
		{
			cin >> u >> v;
		}
		solve(u, v, w);
	}
	return 0;
}