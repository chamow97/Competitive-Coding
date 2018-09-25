//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vecit vector<int> :: iterator
#define vecpit vector< pair<int, int> > :: iterator
#define f first
#define s second


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;
typedef vector< pair<int, int> > vecpair;


/*-------------------------------------------------------- */

const ll MAXN = 2e5 + 100;
vec segTree[5 * MAXN];
vec arr(MAXN, 0);

/*-------------------------------------------------------- */

void build(ll pos, ll l, ll r)
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
	ll mid = (l + r) / 2;
	ll lPos = 2 * pos; 
	ll rPos = lPos + 1;
	build(lPos, l, mid);
	build(rPos, mid + 1, r);
	segTree[pos].resize(segTree[rPos].size() + segTree[lPos].size());
	merge(segTree[lPos].begin(), segTree[lPos].end(), segTree[rPos].begin(), segTree[rPos].end(), segTree[pos].begin());
}

/*-------------------------------------------------------- */

ll query(ll pos, ll l, ll r, ll lRange, ll rRange, ll sum)
{
	if(l > rRange || r < lRange)
	{
		return 0;
	}
	if(l >= lRange && r <= rRange)
	{
		ll position = upper_bound(segTree[pos].begin(), segTree[pos].end(), sum) - segTree[pos].begin();
		return position;
	}
	ll mid = (l + r) / 2;
	ll lPos = 2 * pos;
	ll rPos = lPos + 1;
	return query(lPos, l, mid, lRange, rRange, sum) + query(rPos, mid + 1, r, lRange, rRange, sum);
}

/*-------------------------------------------------------- */

int main()
{
	fastread
	ll n, t, ans = 0;
	cin >> n >> t;
	rep(i,1,n+1)
	{
		cin >> arr[i];
		arr[i] += arr[i-1];
	}
	build(1, 1, n);
	rep(i,1,n+1)
	{
		ans += query(1, 1, n, i, n, arr[i-1] + t - 1);
	}
	cout << ans;
	return 0;
}