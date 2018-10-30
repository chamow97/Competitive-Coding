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

const ll MAXN = 5e5 + 10;
vec dp(MAXN, -1);
ll n;
vec arr(MAXN);
ll solve(ll i)
{
	if(dp[i] != -1)
	{
		return dp[i];
	}
	ll possible = 0;
	for(ll j = i; j <= n; j += arr[i])
	{
		if(arr[j] > arr[i])
		possible |= (1 - solve(j));
	}
	for(ll j = i; j > 0; j -= arr[i])
	{
		if(arr[j] > arr[i])
		possible |= (1 - solve(j));
	}
	dp[i] = possible;
	return possible;
}

int main()
{
	fastread;
	cin >> n;
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	rep(i,1,n+1)
	{
		if(solve(i))
		{
			cout << "A";
		}
		else
		{
			cout << "B";
		}
	}
	return 0;
}