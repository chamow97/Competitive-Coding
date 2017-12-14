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

ll LCS(string str, string str1)
{
	ll dp[str.length() + 10][str.length() + 10];
	memset(dp, 0, sizeof(dp));
	rep(i,1,str.length()+1)
	{
		rep(j,1,str.length()+1)
		{
			if(str[i-1] == str1[j-1])
			{
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[str.length()][str.length()];
}

int main()
{
	fastread;
	ll t;
	cin >> t;
	while(t--)
	{
		string str;
		cin >> str;
		string str1 = str;
		reverse(str.begin(), str.end());
		cout << str.length() - LCS(str, str1) << '\n';
	}
	return 0;
}
