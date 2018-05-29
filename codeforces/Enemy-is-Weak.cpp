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

ll n;
const ll MAXN = 1e6 + 10;
vec segTree[5 * MAXN];
vec arr(MAXN);

void constructTree(ll pos, ll l, ll r)
{
	if(r < l)
	{
		return;
	}
	if(l == r)
	{
		segTree[pos].pb(arr[l]);
		return;
	}
	ll mid = (l + r)/2;
	ll lptr = 2 * pos;
	ll rptr = lptr + 1;
	constructTree(lptr, l, mid);
	constructTree(rptr, mid + 1, r);
	segTree[pos].resize(segTree[lptr].size() + segTree[rptr].size());
	merge(segTree[lptr].begin(), segTree[lptr].end(), segTree[rptr].begin(), segTree[rptr].end(), segTree[pos].begin());
}

ll queryTree(ll pos, ll l, ll r, ll a, ll b, ll val)
{
	if(r < l || a > r || b < l)
	{
		return 0;
	}
	if(a <= l && b >= r)
	{
		ll position;
		position = lower_bound(segTree[pos].begin(), segTree[pos].end(), val) - segTree[pos].begin();
		return position;
	}
	ll mid = (l + r)/2;
	ll lptr = 2 * pos;
	ll rptr = lptr + 1;
	return (queryTree(lptr, l, mid, a, b, val) + queryTree(rptr, mid + 1, r, a, b, val));
}

/*-------------------------------------------------------- */

int main()
{
	fastread;
	cin >> n;
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	constructTree(1, 1, n);
	ll ans = 0;
	rep(i,2,n)
	{
		ll val1 = queryTree(1, 1, n, 1, i - 1, arr[i]);
		ll val2 = queryTree(1, 1, n, i, n, arr[i]);
		// cout << val1 << ' ' << val2 << '\n';
		ans += ((i - 1 - val1) * val2);
	}
	cout << ans;
	return 0;
}