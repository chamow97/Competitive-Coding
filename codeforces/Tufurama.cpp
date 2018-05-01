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

const ll maxn = 2e5 + 100;
vec *segTree = new vec[5*maxn];
vec arr(maxn);
ll n, k;


void getInput()
{
	cin >> n;
	arr.resize(n + 1);
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
}

void build(ll pos, ll l, ll r)
{
	if(l > r)
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
	build(lptr, l, mid);
	build(rptr, mid + 1, r);
	segTree[pos].resize(r - l + 1);
	merge(segTree[lptr].begin(), segTree[lptr].end(), segTree[rptr].begin(), segTree[rptr].end(), segTree[pos].begin());
}

ll query(ll pos, ll l, ll r, ll a, ll b, ll val)
{
	if(b > n)
	{
		b = n;
	}
	if(r < l || a > r || b < l)
	{
		return 0;
	}
	if(a <= l && b >= r)
	{
		ll currAns = 0;
		ll position = lower_bound(segTree[pos].begin(), segTree[pos].end(), val) - segTree[pos].begin();
		currAns = segTree[pos].size() - position;
		// cout << currAns << ' ';
		return currAns;
	}
	ll mid = (l + r)/2;
	ll lptr = 2 * pos;
	ll rptr = lptr + 1;
	ll lAns = query(lptr, l, mid, a, b, val);
	ll rAns = query(rptr, mid + 1, r, a, b, val);
	return lAns + rAns;
}

void getOutput()
{
	ll ans = 0;
	rep(i,1,n)
	{
		ans += query(1, 1, n, i + 1, arr[i], i);
	}
	cout << ans;
}

int main()
{
	fastread;
	getInput();
	build(1, 1, n);
	getOutput();
	return 0;
}