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
//function 
const int n = 3011;
int dp[n][n];
string str;
int solve(ll i, ll j)
{
	if(i >= j)
	{
		return 0;
	}
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}
	ll current = 0;
	if(str[i] != str[j])
	{
		current  += (1 + solve(i + 1, j - 1));
	}
	else
	{
		current  += (solve(i + 1, j - 1));
	}
	return dp[i][j] = current;
}


int main()
{
	fastread;
	int k;
	cin >> str;
	cin >> k;
	memset(dp, -1, sizeof(dp));
	int len = str.length();
	int soln = 0;
	//consider all subsets
	//recursively find the soln
	per(i,len-1,0)
	{
		per(j,len-1,i)
		{
			solve(i,j);
		}
	}
	per(i,len-1,0)
	{
		per(j,len-1,i)
		{
			if(dp[i][j] <= k)
			{
				++soln;
			}
		}
	}
	cout << soln;

	return 0;
}
