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
#define INF 1e15
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
const ll maxn = 1e5+200;
ll arr[maxn];
ll prefix[maxn];
ll segTree[maxn*5];
ll n, d;

// void clearAll()
// {
// 	memset(arr, -INF, sizeof(arr));
// 	memset(prefix, -INF, sizeof(prefix));
// 	memset(segTree, -INF, sizeof(segTree));
// }

void build(ll l, ll r, ll pos)
{
	if(l == r)
	{
		segTree[pos] = prefix[l];
		return;
	}
	ll mid = (l + r)/2;
	build(l, mid, 2*pos);
	build(mid + 1, r, 2*pos + 1);
	segTree[pos] = max(segTree[2*pos], segTree[2*pos + 1]); 
}

ll query(ll l, ll r, ll a, ll b, ll pos)
{
	if(b < l || a > r || a > b)
	{
		return -INF;
	}
	if(l >= a && r <= b)
	{
		return segTree[pos];
	}
	ll mid = (l + r)/2;
	return max(query(l, mid, a, b, 2*pos), query(mid + 1, r, a, b, 2*pos + 1));
}

ll maxVal(ll len)
{
	ll maximum = -INF;
	rep(i,1,n+1)
	{
		ll val = query(0, n, i, min(i + len - 1, n), 1);
		val -= prefix[i-1];
		maximum = max(maximum, val);
	}
	return maximum;
}

ll binarySearch()
{
	ll low = 1, high = n, mid;
	while(low < high)
	{
		mid = (low + high)/2;
		ll val = maxVal(mid);
		if(val >= d)
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	return low;
}


void solve()
{
	// clearAll();
	cin >> n >> d;
	rep(i,1,n+1)
	{
		cin >> arr[i];
		prefix[i] = arr[i] + prefix[i-1];
	}	
	build(0,n,1);
	ll val = maxVal(n);
	if(val < d)
	{
		cout << -1;
	}
	else
		cout << binarySearch();
}

int main()
{
	fastread;
	ll t;
	cin >> t;
	while(t--)
	{
		solve();
		cout << '\n';
	}
	return 0;
}
