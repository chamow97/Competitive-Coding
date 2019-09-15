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

const int BOYS = 4, GIRLS = 1;

ll nCr(ll n, ll r)
{
	ll result = 1;
	if(r > n - r)
	{
		r = n - r;
	}
	rep(i,0,r)
	{
		result *= (n - i);
		result /= (i + 1);
	}
	return result;
}

int main()
{
	ll n, m, t;
	cin >> n >> m >> t;
	ll ans = 0;
	rep(i,BOYS,t)
	{
		int boys = i;
		int girls = t - boys - GIRLS;
		if(girls + GIRLS <= 0 || boys > n || t - boys > m)
		{
			continue;
		}
		ll currBoys = nCr(n, boys);
		ll currGirls = nCr(m, girls + GIRLS);
		ll totalCombinations = (currBoys * currGirls);
		ans += (totalCombinations);
	}
	cout << ans;
	return 0;
}