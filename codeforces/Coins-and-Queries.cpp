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
map<ll, ll> m;

ll solve(ll val)
{
	ll ans = 0;
	for(ll t = 1 << 30; t >= 1; t = t >> 1)
	{
		ll now = min(m[t], val / t);
		ans += now;
		val -= (now * t);
	}
	if(val != 0)
	{
		return -1;
	}
	return ans;
}

int main()
{
	fastread;
	ll n, q;
	cin >> n >> q;
	rep(i,0,n)
	{
		ll val;
		cin >> val;
		m[val]++;
	}
	while(q--)
	{
		ll query;
		cin >> query;
		cout << solve(query) << '\n';
	}
	return 0;
}