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
const ll maxn = 1e5 + 200;
ll ans = 0;
vec ice(maxn + 1, 0);
vec temp(maxn + 1, 0);
vec ending(maxn + 1, 0);
vec prefix(maxn, 0);
vec extra(maxn, 0);

ll binarySearch(ll low, ll high, ll pos)
{
	if(high < low)
	{
		return ans;
	}
	ll mid = (low + high)/2;
	if(prefix[mid] - prefix[pos - 1] >= ice[pos])
	{
		ans = mid;
		high = mid - 1;
		return binarySearch(low, high, pos);
	}
	else
	{
		low = mid + 1;
		return binarySearch(low, high, pos);
	}
}

int main()
{
	fastread;
	ll n;
	cin >> n;
	rep(i,1,n+1)
	{
		cin >> ice[i];
	}
	rep(i,1,n+1)
	{
		cin >> temp[i];
		prefix[i] = prefix[i-1] + temp[i];
	}
	rep(i,1,n+1)
	{
		ans = n + 1;
		ll pos = binarySearch(i, n, i);
		ending[pos]++;
		extra[pos] = extra[pos] + (ice[i] - prefix[pos - 1] + prefix[i - 1]);
	}
	ll curr = 1;
	rep(i,1,n+1)
	{
		curr -= ending[i];
		cout << (curr * temp[i]) + extra[i] << ' ';
		curr++;
	}
	return 0;
}