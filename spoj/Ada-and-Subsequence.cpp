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

int main()
{
	fastread;
	ll n, m;
	cin >> n >> m;
	vec price(26, 0);
	rep(i,0,26)
	{
		ll val;
		cin >> val;
		price[i] = val;
	}
	string str1, str2;
	cin >> str1 >> str2;
	ll dp[n + 10][m + 10];
	memset(dp, 0, sizeof(dp));
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			if(str1[i-1] == str2[j-1])
			{
				dp[i][j] = max(dp[i-1][j-1], price[str1[i-1] - 'a'] + dp[i-1][j-1]);
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1]));
			}
		}
	}
	cout << dp[n][m];
	return 0;
}
