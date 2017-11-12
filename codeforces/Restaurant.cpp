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
vecpair arr;
ll n;
vec dp(1e6, -1);
ll solution = INF;
ll solve(ll curr)
{
	if(curr == -1)
	{
		return 0;
	}
	if(dp[curr] != -1)
	{
		return dp[curr];
	}
	if(arr[curr].s < solution)
	{
		solution = arr[curr].f;
		return dp[curr] = 1 + solve(curr-1);
	}
	else
	{
		return dp[curr] = solve(curr-1);
	}
}	
int main()
{
	fastread;
	cin>>n;
	rep(i,0,n)
	{
		pair<ll, ll> a;
		cin>>a.f>>a.s;
		arr.pb(a);
	}
	sort(arr.begin(), arr.end());
	ll ans = solve(n-1);
	cout<<dp[n-1];
	return 0;
}
