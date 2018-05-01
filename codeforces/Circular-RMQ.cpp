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
vec segTree(4 * maxn, INF);
vec lazy(4 * maxn, 0);
ll n, m;
vec arr(maxn);

void build(ll pos, ll l, ll r)
{
	if(r < l)
	{
		return;
	}
	if(l == r)
	{
		segTree[pos] = arr[l];
		return;
	}
	ll mid = (l + r)/2;
	ll lptr = 2 * pos;
	ll rptr = lptr + 1;
	build(lptr, l, mid);
	build(rptr, mid + 1, r);
	segTree[pos] = min(segTree[lptr], segTree[rptr]);
}

void update(ll pos, ll l, ll r, ll a, ll b, ll x)
{
	if(lazy[pos] != 0)
	{
		segTree[pos] += lazy[pos];
		if(l != r)
		{
			lazy[2 * pos] += lazy[pos];
			lazy[2 * pos + 1] += lazy[pos];
		}
		lazy[pos] = 0;
	}
	if(r < l || a > r || b < l)
	{
		return;
	}
	if(a <= l && b >= r)
	{
		segTree[pos] += x;
		if(l != r)
		{
			lazy[2 * pos] += x;
			lazy[2 * pos + 1] += x;
		}
		return;
	}
	ll mid = (l + r)/2;
	ll lptr = 2 * pos;
	ll rptr = lptr + 1;
	update(lptr, l, mid, a, b, x);
	update(rptr, mid + 1, r, a, b, x);
	segTree[pos] = min(segTree[lptr], segTree[rptr]);
}

ll query(ll pos, ll l, ll r, ll a, ll b)
{
	if(lazy[pos] != 0)
	{
		segTree[pos] += lazy[pos];
		if(l != r)
		{
			lazy[2 * pos] += lazy[pos];
			lazy[2 * pos + 1] += lazy[pos];
		}
		lazy[pos] = 0;
	}
	if(r < l || a > r || b < l)
	{
		return INF;
	}
	if(a <= l && r <= b)
	{
		return segTree[pos];
	}
	ll mid = (l + r)/2;
	ll lptr = 2 * pos;
	ll rptr = lptr + 1;
	ll lAns = query(lptr, l, mid, a, b);
	ll rAns = query(rptr, mid + 1, r, a, b);
	return min(lAns, rAns);
}

int main()
{
	fastread;
	cin >> n;
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	cin >> m;
	build(1, 1, n);
	cin.get();
	while(m--)
	{
		string input;
		getline(cin, input);
		stringstream ss(input);
		ll l, r, x, curr, counter = 0;
		while(ss >> curr)
		{
			++counter;
			if(counter == 1)
			{
				l = curr;
			}
			else if(counter == 2)
			{
				r = curr;
			}
			else
			{
				x = curr;
			}
		}
		++l;
		++r;
		if(counter == 3)
		{
			if(r >= l)
			{
				update(1, 1, n, l, r, x);
			}
			else
			{
				update(1, 1, n, l, n, x);
				update(1, 1, n, 1, r, x);
			}
		}
		else
		{
			if(r >= l)
			{
				cout << query(1, 1, n, l, r) << '\n';
			}
			else
			{
				ll ans = INF;
				ans = query(1, 1, n, l, n);
				ans = min(ans, query(1, 1, n, 1, r));
				cout << ans << '\n';
			}
		}
	}
	return 0;
}