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
	string str1, str2;
	cin >> str1 >> str2;
	ll len1 = str1.length();
	ll len2 = str2.length();
	int dp[100100][15];
	rep(i,0,len1+1)
	{
		rep(j,0,len2)
		{
			dp[i][j] = 0;
		}
	}
	rep(i,0,len1+1)
	{
		dp[i][0] = 1;
	}
	rep(i,1,len1+1)
	{
		rep(j,1,len2+1)
		{
			if(str1[i-1] == str2[j-1])
			{
				dp[i][j] = (dp[i-1][j-1] % MODULO + dp[i-1][j] % MODULO) % MODULO;
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[len1][len2];
	return 0;
}
