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

vec dp[100001];
vec arr[100001];

ll solve(ll i, ll j)
{
	if(i > n)
	{
		return 0;
	}
	if(dp[i][j] != 0)
	{
		return dp[i][j];
	}
	ll ans = 0;
	if((i < n) && arr[i + 1][j] >= arr[i][j])
	{
		ans = 1 + solve(i + 1, j);
	}
	else
	{
		ans = 1;
	}
	dp[i][j] = ans;
	return dp[i][j];
}

int main()
{
	fastread;
	cin >> n >> m;
	rep(i,0,n+1)
	{
		rep(j,0,m+1)
		{
			dp[i].pb(0);
		}
	}
	rep(i,1,n+1)
	{
		arr[i].pb(0);
		rep(j,1,m+1)
		{
			ll val;
			cin >> val;
			arr[i].pb(val);
		}
	}
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			solve(i, j);
		}
	}
	vec maxArr(n + 1, 0);
	rep(i,1,n+1)
	{
		ll maxm = 0;
		rep(j,1,m+1)
		{
			maxm = max(maxm, dp[i][j]);
		}
		maxArr[i] = maxm;
	}
	ll k;
	cin >> k;
	while(k--)
	{
		ll l, r;
		cin >> l >> r;
		if(maxArr[l] >= (r - l + 1))
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
		cout << '\n';
	}
	return 0;
}