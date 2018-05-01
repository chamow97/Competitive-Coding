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

const ll maxn = 1e5 + 5;
ll n, m;
vec arr(maxn);
ll segTree[21][4*maxn];
ll lazy[21][4*maxn];

void build(ll pos, ll l, ll r)
{
	if(r < l)
	{
		return;
	}
	if(l == r)
	{
		ll now = arr[l];
		rep(i,0,21)
		{
			segTree[i][pos] = (now % 2);
			now /= 2;
		}
		return;
	}
	ll mid = (l + r)/2;
	ll lptr = 2 * pos;
	ll rptr = lptr + 1;
	build(lptr, l, mid);
	build(rptr, mid + 1, r);
	rep(i,0,21)
	{
		segTree[i][pos] = segTree[i][lptr] + segTree[i][rptr];
	}
}

void update(ll pos, ll l, ll r, ll a, ll b, ll x)
{
	rep(i,0,21)
	{
		if(lazy[i][pos] != 0)
		{
			segTree[i][pos] = (r - l + 1) - segTree[i][pos];
			if(l != r)
			{
				lazy[i][2*pos] = (lazy[i][2*pos] + lazy[i][pos]) % 2;
				lazy[i][2*pos + 1] = (lazy[i][2*pos + 1] + lazy[i][pos]) % 2;
			}
			lazy[i][pos] = 0;
		}
	}

	if(r < l || a > r || b < l)
	{
		return;
	}
	if(l >= a && r <= b)
	{
		rep(i,0,21)
		{
			if((x & (1 << i)))
			{
				segTree[i][pos] = (r - l + 1) - segTree[i][pos];
				if(l != r)
				{
					lazy[i][2*pos] = (lazy[i][2*pos] + 1) % 2;
					lazy[i][2*pos + 1] = (lazy[i][2 * pos + 1] + 1) % 2;
				}
			}
		}
		return;
	}
	ll mid = (l + r)/2;
	ll lptr = 2 * pos;
	ll rptr = lptr + 1;
	update(lptr, l, mid, a, b, x);
	update(rptr, mid + 1, r, a, b, x);
	rep(i,0,21)
	{
		segTree[i][pos] = segTree[i][lptr] + segTree[i][rptr];
	}
}

ll query(ll pos, ll l, ll r, ll a, ll b)
{
	rep(i,0,21)
	{
		if(lazy[i][pos] != 0)
		{
			segTree[i][pos] = (r - l + 1) - segTree[i][pos];
			if(l != r)
			{
				lazy[i][2*pos] = (lazy[i][2*pos] + lazy[i][pos]) % 2;
				lazy[i][2*pos + 1] = (lazy[i][2*pos + 1] + lazy[i][pos]) % 2;
			}
			lazy[i][pos] = 0;
		}
	}
	if(l > r || a > r || b < l)
	{
		return 0;
	}
	if(a <= l && r <= b)
	{	
		ll sum = 0;
		rep(i,0,21)
		{
			sum = sum + ((1 << i) * segTree[i][pos]);
		}
		return sum;
	}
	ll mid = (l + r)/2;
	ll lptr = 2 * pos;
	ll rptr = lptr + 1;
	ll lSum = query(lptr, l, mid, a, b);
	ll rSum = query(rptr, mid + 1, r, a, b);
	return lSum + rSum;
}


int main()
{
	fastread;
	cin >> n;
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	build(1, 1, n);
	cin >> m;
	while(m--)
	{
		ll type;
		cin >> type;
		if(type == 1)
		{
			ll l, r;
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << '\n';
		}
		else
		{
			ll l, r, x;
			cin >> l >> r >> x;
			update(1, 1, n, l, r, x);
		}
	}
	return 0;
}