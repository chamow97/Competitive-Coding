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

ll dp[5010][5010];
ll LongestCommonSubsequence(string str1, string str2)
{
	rep(i,0,5001)
	{
		rep(j,0,5001)
		{
			dp[i][0] = 0;
			dp[0][i] = 0;
		}
	}

	rep(i,1,str1.length() + 1)
	{
		rep(j,1,str2.length() + 1)
		{
			if(str1[i-1] == str2[j-1])
			{
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[str1.length()][str2.length()];
}

int main()
{
	fastread;
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, m;
		cin >> n >> m;
		string a, b;
		cin >> a >> b;

		//clean a, b
		string str1 = "";
		str1 += a[0]; 
		string str2 = "";
		str2 += b[0];
		
		rep(i,1,a.length())
		{
			if(a[i] != a[i-1])
			{
				str1 += a[i];
			}
		}

		rep(i,1,b.length())
		{
			if(b[i] != b[i-1])
			{
				str2 += b[i];
			}
		}
		n = str1.length();
		m = str2.length();
		ll lcs = LongestCommonSubsequence(str1, str2);

		cout << n + m - lcs << '\n';
	}
	return 0;
}
