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
const ll maxn = 40000;
ll n;
string str;
vec arr(maxn,0);
vecpair segTree(4*maxn,mp(0,0));
void clear()
{
	fill(arr.begin(), arr.end(), 0);
	fill(segTree.begin(), segTree.end(), mp(10,10));
}

void construct(ll low, ll high, ll pos)
{
	if(low == high)
	{
		segTree[pos].f = arr[low];
		segTree[pos].s = arr[low];
	}
	else
	{
		ll mid = (low + high)/2;
		construct(low, mid, 2*pos + 1);
		construct(mid + 1, high, 2*pos + 2);
		segTree[pos].f = segTree[2*pos + 1].f + segTree[2*pos + 2].f;
		segTree[pos].s = min(segTree[2*pos + 1].s, segTree[2 * pos + 1].f + segTree[2*pos + 2].s);
	}
}

void pointUpdate(ll low, ll high, ll pos, ll i, ll j)
{
	if(low > high)
	{
		return;
	}
	if(low > high || low > j || high < i)
	{
		return;
	}
	if(low >= i && high <= j)
	{
		segTree[pos].f = segTree[pos].s = (-1)*(segTree[pos].f);
		return;
	}
	ll mid = (low + high)/2;
	pointUpdate(low, mid, 2*pos + 1, i, j);
	pointUpdate(mid + 1, high, 2*pos + 2, i, j);
	segTree[pos].f = segTree[2*pos + 1].f + segTree[2*pos + 2].f;
	segTree[pos].s = min(segTree[2*pos + 1].s, segTree[2*pos + 1].f + segTree[2*pos + 2].s);
}

void solve()
{
	clear();
	cin >> n;
	cin >> str;
	rep(i,0,n)
	{
		if(str[i] == '(')
		{
			arr[i] = 1;
		}
		else
		{
			arr[i] = -1;
		}
	}
	construct(0ll, n-1, 0ll);
	ll m;
	cin >> m;
	while(m--)
	{
		ll type;
		cin >> type;
		if(type == 0)
		{
			ll value = segTree[0].f;
			ll value1 = segTree[0].s;
			if(value == 0 && value1 == 0)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
		else
		{
			--type;
			pointUpdate(0, n-1, 0, type, type);
		}
	}

}

int main()
{
	fastread;
	ll t = 10;
	while(t--)
	{
		cout << "Test " << 10 - t << ":\n";
		solve();
	}
	return 0;
}
