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

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
	return a.f < b.f;
}

void solve()
{
	ll n;
	cin >> n;
	vecpair v;
	rep(i,0,n)
	{
		ll a, b;
		cin >> a >> b;
		v.pb(mp(a,b));
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	ll curr = INF;
	per(i,n-1,0)
	{
		if(v[i].second <= curr)
		{
			curr = v[i].first;
			++ans;
		}
	}
	cout << ans << '\n';
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
