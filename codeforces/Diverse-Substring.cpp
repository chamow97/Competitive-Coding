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
	ll n;
	cin >> n;
	string str;
	cin >> str;
	int dp[n + 1][26];
	rep(i,1,n + 1)
	{
		rep(j,0,26)
		{
			dp[i][j] = 0;
		}
	}
	rep(i,1,n+1)
	{
		dp[i][str[i - 1] - 'a']++;
	}
	rep(i,1,n + 1)
	{
		rep(j,0,26)
		{
			dp[i][j] += dp[i-1][j];
		}
	}
	rep(i,1,n+1)
	{
		rep(j,i+1,n+1)
		{
			ll len = j - i + 1;
			bool possible = true;
			rep(k,0,26)
			{
				if(dp[j][k] - dp[i - 1][k] > (len / 2))
				{
					possible = false;
					break;
				}
			}
			if(possible)
			{
				cout << "YES\n";
				rep(k,i,j+1)
				{
					cout << str[k - 1];
				}
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}