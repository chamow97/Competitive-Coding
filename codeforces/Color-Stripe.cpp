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

ll n, k;
string str;
ll dp[600000][30];

ll solve(ll prev, ll start)
{
	if(start > n)
	{
		return 0;
	}
	if(dp[start][prev] != INF)
	{
		return dp[start][prev];
	}
	ll now = INF;
	if((str[start] - 'A') != prev)
	{
		now = solve((str[start] - 'A'), start + 1);
	}
	rep(i,0,k)
	{
		if(i != prev)
		{
			now = min(1 + solve(i, start + 1), now);
		}
	}
	dp[start][prev] = now;
	return dp[start][prev];
}

int main()
{
	fastread;
	memset(dp, 1e9, sizeof dp);
	cin >> n >> k >> str;
	ll ans = solve((str[0] - 'A'), 1);
	cout << ans << '\n';
	// rep(i,1,n+1)
	// {
	// 	rep(j,0,k)
	// 	{
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	str = '$' + str;
	string total = "";
	total += '$';
	rep(i,1,n+1)
	{	
		ll curr = (str[i] - 'A');
		ll minVal = dp[i][curr];
		ll minPos = curr;
		rep(k,0,26)
		{
			if(dp[i][k] < minVal && dp[i][k] != INF && k != (total[i - 1] - 'A'))
			{
				minVal = dp[i][k];
				minPos = k;
			}
		}
		total += char(minPos + 'A');
	}
	rep(i,1,n+1)
	{
		cout << total[i];
	}
	return 0;
}