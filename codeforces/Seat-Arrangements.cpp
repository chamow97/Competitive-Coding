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
	ll n, m, k;
	cin >> n >> m >> k;
	char mat[n+100][m+100];
	rep(i,0,n)
	{
		cin >> mat[i];
	}
	ll ans = 0;
	rep(i,0,n)
	{
		ll rowCount = 0;
		ll currCount = 1;
		rep(j,0,m)
		{
			if(mat[i][j] == '*')
			{
				continue;
			}
			if(j < m-1 && mat[i][j] == mat[i][j+1])
			{
				++currCount;
			}
			else
			{
				if(currCount >= k)
				{
					ans += (currCount - k + 1);
				}
				currCount = 1;
			}
		}
	}
	rep(j,0,m)
	{
		ll rowCount = 0;
		ll currCount = 1;
		rep(i,0,n)
		{
			if(mat[i][j] == '*')
			{
				continue;
			}
			if(i < n-1 && mat[i][j] == mat[i+1][j])
			{
				++currCount;
			}
			else
			{
				if(currCount >= k)
				{
					ans += (currCount - k + 1);
				}
				currCount = 1;
			}
		}
	}
	if(k == 1)
	{
		cout << ans/2;
		return 0;
	}
	cout << ans;
	return 0;
}