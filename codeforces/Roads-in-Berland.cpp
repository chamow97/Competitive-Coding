//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vecit vector<int> :: iterator
#define vecpit vector< pair<int, int> > :: iterator
#define f first
#define s second


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<int> vec;
typedef vector< pair<int, int> > vecpair;


/*-------------------------------------------------------- */
int main()
{
	fastread
	ll n, sum = 0;
	cin >> n;
	ll dp[n+1][n+1];
	ll temp[n+1][n+1];
	rep(i,0,n+1)
	{
		rep(j,0,n+1)
		{
			dp[i][j] = 0;
			temp[i][j] = 0;
		}
	}
	rep(i,1,n+1)
	{
		rep(j,1,n+1)
		{
			cin >> dp[i][j];
			if(j > i)
			{
				sum += dp[i][j];
			}
		}
	}
	ll k;
	cin >> k;
	rep(i,1,k+1)
	{
		ll x, y, w;
		cin >> x >> y >> w;
		if(dp[x][y] <= w)
		{
			cout << sum;
		}
		else
		{
			sum = 0;
			dp[x][y] = w;
			dp[y][x] = w;
			rep(j,1,n+1)
			{
				rep(m,1,n+1)
				{
					temp[j][m] = min(dp[j][m], dp[j][x] + dp[x][y] + dp[y][m]);
				}
			}

			rep(j,1,n+1)
			{
				rep(m,1,n+1)
				{
					temp[j][m] = min(temp[j][m], dp[j][y] + dp[y][x] + dp[x][m]);
				}
			}

			rep(j,1,n+1)
			{
				rep(m,1,n+1)
				{
					if(m > j)
					{
						sum += temp[j][m];
					}
					dp[j][m] = temp[j][m];
					temp[j][m] = 0;
				}
			}
			cout << sum;
		}
		cout << " ";
	}
	return 0;
}