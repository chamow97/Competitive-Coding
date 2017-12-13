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
ll val;
vec segTree(1e6, 0);
vec arr(2e5, 0);
void constructTree(ll low, ll high, ll pos, ll orOrXor)
{
	if(low == high)
	{
		segTree[pos] = arr[low - 1];
	}
	else
	{
		ll mid = (low + high)/2;
		constructTree(low, mid, 2*pos, !orOrXor);
		constructTree(mid + 1, high, 2*pos + 1, !orOrXor);
		if(orOrXor == 1)
		{
			segTree[pos] = segTree[(2*pos)] | segTree[(2*pos)+1];
		}
		else
		{
			segTree[pos] = segTree[(2*pos)] ^ segTree[(2*pos)+1];
		}
	}
}
void updateTree(ll current, ll low, ll high, ll pos, ll orOrXor)
{
	if(low > high or low > current or high < current)
	{
		return;
	}
	if(low == high)
	{
		segTree[pos] = arr[low - 1];
		return;
	}
	ll mid = (low + high)/2;
	updateTree(current, low, mid, 2*pos, !orOrXor);
	updateTree(current, mid + 1, high, 2*pos + 1, !orOrXor);
	if(orOrXor == 1)
	{
		segTree[pos] = segTree[(2*pos)] | segTree[(2*pos)+1];
	}
	else
	{
		segTree[pos] = segTree[(2*pos)] ^ segTree[(2*pos)+1];
	}
}
int main()
{
	fastread;
	cin >> n >> m;
	rep(i,0,1<<n)
	{
		cin >> arr[i];
	}
	constructTree(1ll, 1<<n, 1ll, (n % 2));
	// rep(i,0,4*(1<<n))
	// {
	// 	cout << segTree[i] << " ";
	// }
	rep(i,0,m)
	{
		ll l, r;
		cin >> l >> r;
		arr[l-1] = r;
		updateTree(l, 1ll, 1<<n, 1ll, (n % 2));
		cout << segTree[1] << '\n';
	}
	return 0;
}
