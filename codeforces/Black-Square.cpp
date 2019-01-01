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
	char grid[n + 1][m + 1];
	rep(i,1,n+1)
	{
		cin >> 1 + grid[i];
	}
	ll white = 0, black = 0;
	ll minRow = INF, minCol = INF;
	ll maxRow = 0,  maxCol = 0;
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			if(grid[i][j] == 'B')
			{
				black++;
				minRow = min(minRow, i);
				minCol = min(minCol, j);
				maxRow = max(maxRow, i);
				maxCol = max(maxCol, j);
			}
			else
			{
				white++;
			}
		}
	}
	if(white == (n * m))
	{
		cout << 1;
		return 0;
	}
	ll ans = 0;
	ll rowDiff = maxRow - minRow + 1;
	ll colDiff = maxCol - minCol + 1;
	ll maxDiff = max(rowDiff, colDiff);
	if(maxDiff > n || maxDiff > m)
	{
		cout << -1;
		return 0;
	}
	ans = (maxDiff * maxDiff) - black;
	cout << ans;
	return 0;
}