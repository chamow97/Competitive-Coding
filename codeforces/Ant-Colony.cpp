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

struct node
{
	ll gcd;
	node()
	{
		gcd = 0;
	}

	void merge(node L, node R)
	{
		gcd = __gcd(L.gcd, R.gcd);
	}

};
const ll maxn = 1e5 + 100;
vec arr(maxn, 0);
vector<node> segTree(5 * maxn);


void build(ll pos, ll l, ll r)
{
	if(l == r)
	{
		segTree[pos].gcd = arr[l];
		return;
	}
	ll mid = (l + r)/2;
	ll lptr = 2 * pos + 1;
	ll rptr = 2 * pos + 2;
	build(lptr, l, mid);
	build(rptr, mid + 1, r);
	segTree[pos].merge(segTree[lptr], segTree[rptr]);
}

node query(ll pos, ll l, ll r, ll a, ll b)
{
	if(r < l || a > r || b < l)
	{
		node temp;
		return temp;
	}
	if(a <= l && b >= r)
	{
		return segTree[pos];
	}
	ll mid = (l + r)/2;
	ll lptr = 2 * pos + 1;
	ll rptr = 2 * pos + 2;
	node x = query(lptr, l, mid, a, b);
	node y = query(rptr, mid + 1, r, a, b);
	node z;
	z.gcd = __gcd(x.gcd, y.gcd);
	return z;
}

ll n, q;
int main()
{
	fastread;
	cin >> n;
	vecpair brr(n+1);
	rep(i,1,n+1)
	{
		cin >> arr[i];
		brr[i] = mp(arr[i], i);
	}
	sort(brr.begin(), brr.end());
	build(1, 1, n);
	ll q;
	cin >> q;
	while(q--)
	{
		ll l, r;
		cin >> l >> r;
		node ans = query(1, 1, n, l, r);
		ll nowGCD = ans.gcd;
		pair<ll, ll> p1 = mp(nowGCD, l);
		ll from = (lower_bound(brr.begin(), brr.end(), p1) - (brr.begin() + 1));
		pair<ll, ll> p2 = mp(nowGCD, r + 1);
		ll to = (lower_bound(brr.begin(), brr.end(), p2) - (brr.begin() + 1));
		cout << (r - l + 1) - (to - from) << '\n';

	}
	return 0;
}