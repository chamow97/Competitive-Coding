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

ll n, m;
const ll maxn = 1e5+100;
vec arr(maxn, 0);
vec segTree[5*maxn];
ll lastAns = 0;

void merge(ll pos, ll lpos, ll rpos)
{
	ll i = 0, j = 0;
	while(i < segTree[lpos].size() && j < segTree[rpos].size())
	{
		if(segTree[lpos][i] > segTree[rpos][j])
		{
			segTree[pos].pb(segTree[rpos][j++]);
		}
		else
		{
			segTree[pos].pb(segTree[lpos][i++]);
		}
	}
	while(i < segTree[lpos].size())
	{
		segTree[pos].pb(segTree[lpos][i]);
		i++;
	}
	while(j < segTree[rpos].size())
	{
		segTree[pos].pb(segTree[rpos][j]);
		j++;
	}
}

void build(ll pos, ll l, ll r)
{
	if(l == r)
	{
		segTree[pos].pb(arr[l]);
		return;
	}
	ll mid = (l + r)/2;
	build(2*pos + 1, l, mid);
	build(2*pos + 2, mid + 1, r);
	merge(pos, 2*pos + 1, 2*pos + 2);
}

ll query(ll pos, ll l, ll r, ll a, ll b, ll k)
{
	if(r < a || l > b || b < a)
	{
		return 0;
	}
	else if(l >= a && r <= b)
	{
		ll high = segTree[pos].end() - upper_bound(segTree[pos].begin(), segTree[pos].end(), k);
		return high;
	}
	else
	{
		ll mid = (l + r)/2;
		ll lQ = query(2*pos + 1, l, mid, a, b, k);
		ll rQ = query(2*pos + 2, mid + 1, r, a, b, k);
		return lQ + rQ;
	}
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
	while(m--)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		a = a ^ lastAns;
		b = b ^ lastAns;
		c = c ^ lastAns;
		if(a < 1)
		{
			a = 1;
		}
		if(b > n)
		{
			b = n;
		}
		// cout << a << ' ' << b << ' ' << c << '\n';
		lastAns = query(1, 1, n, a, b, c);
		cout << lastAns << '\n';
	}
	return 0;
}