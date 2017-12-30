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
	ll ip[n+10][m+10];
	ll dp1[n+10][m+10];
	ll dp2[n+10][m+10];
	ll dp3[n+10][m+10];
	ll dp4[n+10][m+10];
	//refresh
	ll answer = 0;
	rep(i,0,n+10)
	{
		rep(j,0,m+10)
		{
			dp1[i][j] = 0;
			dp2[i][j] = 0;
			dp3[i][j] = 0;
			dp4[i][j] = 0;
		}
	}
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			cin >> ip[i][j];
		}
	}
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]) + ip[i][j];
		}
	}
	rep(i,1,n+1)
	{
		per(j,m,1)
		{
			dp2[i][j] = max(dp2[i-1][j], dp2[i][j+1]) + ip[i][j];
		}
	}
	per(i,n,1)
	{
		rep(j,1,m+1)
		{
			dp3[i][j] = max(dp3[i+1][j], dp3[i][j-1]) + ip[i][j];
		}
	}
	per(i,n,1)
	{
		per(j,m,1)
		{
			dp4[i][j] = max(dp4[i+1][j], dp4[i][j+1]) + ip[i][j];
		}
	}

	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			//they can never meet here
			if(i == 1 || i == n || j == 1 || j == m)
			{
				continue;
			}
			answer = max(answer, dp1[i-1][j] + dp4[i+1][j] + dp3[i][j-1] + dp2[i][j+1]);
			answer = max(answer, dp1[i][j-1] + dp4[i][j+1] + dp3[i+1][j] + dp2[i-1][j]);
		}
	}
	cout << answer;
	return 0;
}
