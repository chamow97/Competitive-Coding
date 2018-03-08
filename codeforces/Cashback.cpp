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

ll n, c;
const ll maxn = 1e5 + 100;
vec arr(maxn);
vec prefix(maxn, 0);
vec segTree[5*maxn];
vec dp(maxn, 0);

void buildTree(ll pos, ll l, ll r)
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
	ll lptr = (2*pos);
	ll rptr = (2*pos) + 1;
	buildTree(lptr, l, mid);
	buildTree(rptr, mid + 1, r);
	segTree[pos].resize(segTree[lptr].size() + segTree[rptr].size());
	merge(segTree[lptr].begin(), segTree[lptr].end(), segTree[rptr].begin(), segTree[rptr].end(), segTree[pos].begin());
}

ll query(ll pos, ll l, ll r, ll a, ll b)
{
	if(l > r || a > r || b < l)
	{
		return INF;
	}
	else if(a <= l && r <= b)
	{
		return segTree[pos][0];
	}
	ll mid = (l + r)/2;
	ll lptr = 2*pos;
	ll rptr = 2*pos + 1;
	return min(query(lptr, l, mid, a, b) , query(rptr, mid + 1, r, a, b));
}

int main()
{
	fastread;
	cin >> n >> c;
	rep(i,1,n+1)
	{
		cin >> arr[i];
		prefix[i] = prefix[i-1] + arr[i];
	}
	rep(i,1,min(n+1,c))
	{
		dp[i] = dp[i-1] + arr[i];
	}
	//we can take either segment of length C or 1
	//we try both the possibility for each either previous + arr[i] or (current - c)th + minimum of this segment
	//since we take only length of C segments in second case C/C = 1, ie. we take only the smallest of a segment
	buildTree(1, 1, n);
	rep(i,c,n+1)
	{
		dp[i] = min(dp[i-1] + arr[i], dp[i-c] + prefix[i] - prefix[i - c] - query(1, 1, n, i - c + 1, i));
		// cout << dp[i] << ' ';
	}
	cout << dp[n];
	return 0;	
}