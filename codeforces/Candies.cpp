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

ll ans = 0;
ll n;

void binarySearch(ll low, ll high)
{
	if(high < low)
	{
		return;
	}
	ll mid = (low + high) / 2;
	ll curr = n;
	ll vasya = 0;
	ll petya = 0;
	while(curr > 0)
	{
		vasya += (min(mid, curr));
		curr -= min(mid, curr);
		petya += (curr / 10);
		curr -= (curr / 10);
	}
	if(vasya >= (n + 1) / 2)
	{
		ans = mid;
		high = mid - 1;
	}
	else
	{
		low = mid + 1;
	}
	binarySearch(low, high);
}

int main()
{
	fastread;
	cin >> n;
	binarySearch(1, n);
	cout << ans;
	return 0;
}