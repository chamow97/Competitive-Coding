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
const ll maxn = 1e5 + 100;
ll n;
vec *adj = new vec[maxn];
vec level(maxn, 0);

void dfs(ll s, ll l)
{
	level[l]++;
	for(auto i : adj[s])
	{
		dfs(i, l + 1);
	}
}

int main()
{
	fastread;
	ll ans = 0;
	cin >> n;
	rep(i,2,n+1)
	{
		ll val;
		cin >> val;
		adj[val].pb(i);
	}
	dfs(1, 0);
	rep(i,0,n+1)
	{
		ans += (level[i] % 2);
	}
	cout << ans;
	return 0;
}