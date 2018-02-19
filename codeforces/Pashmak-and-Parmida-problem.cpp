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
typedef vector<int> vec;
typedef vector< pair<int, int> > vecpair;


/*-------------------------------------------------------- */

int gcd(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

int lcm(int a, int b)
{
	return ((a*b)/gcd(a,b));
}

/*-------------------------------------------------------- */
int n;
const int maxn = 1e6+100;
vec arr(maxn);
vec segTree[4 * maxn];
vec counter(maxn, 0);
vec required(maxn, 0);
map<int, int> m;

int compressVal = 0;
int mapper(int val)
{
	int now = m[val];
	if(now == 0)
	{
		compressVal++;
		m[val] = compressVal;
		return compressVal;
	}
	else
	{
		return now;
	}
}

void merge(int pos, int lpos, int rpos)
{
	int i = 0, j = 0;
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

void build(int pos, int l, int r)
{
	if(r < l)
	{
		return;
	}
	if(l == r)
	{
		segTree[pos].pb(required[l]);
		return;
	}
	int mid = (l + r)/2;
	int lptr = 2*pos;
	int rptr = 2*pos + 1;
	build(lptr, l, mid);
	build(rptr, mid + 1, r);
	merge(pos, lptr, rptr);
}

int query(int pos, int l, int r, int a, int b, int k)
{
	if(a > r || b < l)
	{
		return 0;
	}
	else if(a <= l && b >= r)
	{
		int position = (lower_bound(segTree[pos].begin(), segTree[pos].end(), k) - segTree[pos].begin());
		return position;
	}
	else
	{	
		int mid = (l + r)/2;
		int lVal = query(2*pos, l, mid, a, b, k);
		int rVal = query(2*pos + 1, mid + 1, r, a, b, k);
		return (lVal + rVal);
	}
}

int main()
{
	fastread;
	cin >> n;
	ll ans = 0;
	rep(i,1,n+1)
	{
		cin >> arr[i];
		arr[i] = mapper(arr[i]);
	}
	//mapper
	per(j,n,1)
	{
		required[j] = ++counter[arr[j]];
	}
	build(1, 1, n);
	rep(i,1,n)
	{
		ans += ll(query(1, 1, n, i + 1, n, counter[arr[i]] - required[i] + 1));
	}
	cout << ans;
	return 0;
}	