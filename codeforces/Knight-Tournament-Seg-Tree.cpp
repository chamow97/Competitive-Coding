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

const ll maxn = 3e5 + 100;
ll n, m;
boolean done(5 * maxn, false);
vec ans(5 * maxn, 0);

void update(ll pos, ll l, ll r, ll a, ll b, ll val)
{
	if(l > r)
	{
		return;
	}
	if(r < a || l > b)
	{
		return;
	}
	if(done[pos])
	{
		return;
	}
	if(l >= a && r <= b)
	{
		done[pos] = true;
	}
	if(l == r)
	{
		ans[l] = val;
		return;
	}
	ll mid = (l + r)/2;
	ll lptr = 2 * pos;
	ll rptr = lptr + 1;
	update(lptr, l, mid, a, b, val);
	update(rptr, mid + 1, r, a, b, val);
	done[pos] = done[lptr] && done[rptr];
}

int main()
{
	fastread;
	cin >> n >> m;
	rep(i,0,m)
	{
		ll l, r, x;
		cin >> l >> r >> x;
		update(1, 1, n, l, x-1, x);
		update(1, 1, n, x + 1, r, x);
	}
	rep(i,1,n+1)
	{
		cout << ans[i] << ' ';
	}

	return 0;
}