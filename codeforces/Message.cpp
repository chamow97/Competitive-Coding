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

void solve()
{
	string str1, str2;
	ll maximum = 0;
	cin >> str1 >> str2;
	ll a = str1.length();
	ll b = str2.length();
	ll dp[a + 10][b + 10];
	rep(i,0,a+1)
	{
		dp[i][0] = 0;
	}
	rep(i,0,b+1)
	{
		dp[0][i] = 0;
	}
	//calc how much you can extract from the given string to get new
	//others you have to do some operation
	rep(i,1,a+1)
	{
		rep(j,1,b+1)
		{
			dp[i][j] = dp[i-1][j-1];
			if(str1[i-1] == str2[j-1])
			{
				dp[i][j] += 1;
			}
			maximum = max(maximum, dp[i][j]);
		}
	}
	cout << b - maximum;	
}

int main()
{
	fastread;
	solve();
	return 0;
}
