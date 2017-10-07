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
ll maxn = 1000001;
vec dp(maxn,0);
int main()
{
	fastread;
	ll a;
	cin>>a;
	dp[1] = 1;
	dp[2] = 2;
	rep(i,3,maxn)
	{
		if(i % 2 == 1)
		{
			dp[i] = dp[i-1];
		}
		else
		{
			dp[i] = dp[i-1] + 1;
		}
	}
	rep(i,1,maxn)
	{
		if(dp[i] == a)
		{
			cout<<i<<" "<<2<<'\n';
			cout<<"1 2";
			return 0;
		}
	}
	return 0;
}
