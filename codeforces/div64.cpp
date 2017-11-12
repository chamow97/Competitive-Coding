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
	string str;
	cin>>str;
	ll n = str.length();
	vec dp(n+10, 0);
	per(j,n-1,0)
	{
		if(str[j] == '0')
		{
			dp[j] = 1 + dp[j+1];
		}
		else
		{
			dp[j] = dp[j+1];
		}
	}
	bool possible = false;
	rep(i,0,n)
	{
		if(str[i] == '1')
		{
			if(dp[i] >= 6)
			{
				possible = true;
				break;
			}
		}
	}
	if(possible)
	{
		cout<<"yes";
	}
	else
	{
		cout<<"no";
	}
	return 0;
}
