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

string str;
const ll MAXN = 2e5 + 10;
ll dp[MAXN][3];

ll solve(ll start, ll mod)
{
	if(start >= str.length())
	{
		return mod == 0;
	}
	if(dp[start][mod] != -1)
	{
		return dp[start][mod];
	}
	ll currAns = 0;
	if(mod == 0)
	{
		currAns = 1 + solve(start + 1, ((str[start] - '0') % 3));
	}
	else
	{
		currAns = max(solve(start + 1, (str[start] - '0') % 3), solve(start + 1, ((mod * 10) + (str[start] - '0')) % 3));
	}
	dp[start][mod] = currAns;
	return dp[start][mod];
}

int main()
{
	fastread;
	cin >> str;
	memset(dp, -1, sizeof dp);
	cout << solve(1ll, (str[0] - '0') % 3);
	return 0;
}