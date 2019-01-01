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
	char dp[n + 1][m + 1];
	ll right[n + 1][m + 1];
	memset(right, 0, sizeof(right));
	rep(i,1,n+1)
	{
		cin >> 1 + dp[i];
	}
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			if(dp[i][j] == '1')
			{
				right[i][j] = 1 + right[i][j - 1];
			}
		}
	}
	ll ans = 0;
	rep(j,1,m+1)
	{
		vec temp(5005, 0);
		rep(i,1,n+1)
		{
			temp[right[i][j]]++;
		}
		per(i,5000,0)
		{
			temp[i] += temp[i + 1];
		}
		rep(i,0,5001)
		{
			ans = max(ans, temp[i] * i);
		}
	}
	cout << ans;
	return 0;
}