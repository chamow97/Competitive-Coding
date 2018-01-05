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

ll calcFunction(ll cur, ll n, ll m)
{
	ll counter = 0;
	rep(i,1,n+1)
	{
		counter += (min(m, (cur - 1)/i));
	}
	return counter;
}


void solve()
{
	ll n, m, k;
	cin >> n >> m >> k;

	ll low = 1, high = n * m + 1;
	while(low < high)
	{
		ll mid = (low + high)/2;
		if(calcFunction(mid, n, m) < k)
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
	}
	cout << low - 1;
}


int main()
{
	fastread;
	solve();
	return 0;
}
