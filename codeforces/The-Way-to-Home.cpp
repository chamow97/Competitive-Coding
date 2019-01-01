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

ll n, d;

vec dp(101, -1);
bool possible = true;

ll solve(ll now, string &str)
{
	if(now >= n)
	{
		return 0;
	}
	if(dp[now] != -1)
	{
		return dp[now];
	}
	ll curr = INF;
	ll counter = 0;
	rep(i,now + 1,min(n, now + d) + 1)
	{
		if(str[i] == '1')
		{
			++counter;
			curr = min(curr, 1 + solve(i, str));
		}
	}
	if(counter == 0)
	{
		return INF;
	}
	dp[now] = curr;
	return dp[now];
}

int main()
{
	fastread;
	string str;
	cin >> n >> d;
	cin >> str;
	str = '0' + str;
	ll ans = solve(1, str);
	if(ans >= INF)
	{
		cout << -1;
		return 0;
	}
	cout << ans;
	return 0;
}