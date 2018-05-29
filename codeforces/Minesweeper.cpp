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

int main()
{
	fastread;
	ll n, m;
	cin >> n >> m;
	char arr[n+10][m+10];
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			cin >> arr[i][j];
		}
	}
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			if(arr[i][j] == '.')
			{
				ll mines = 0;
				rep(k,j-1,j+2)
				{
					if(arr[i-1][k] == '*')
					{
						++mines;
					}
					if(arr[i+1][k] == '*')
					{
						++mines;
					}
				}
				if(arr[i][j-1] == '*')
				{
					++mines;
				}
				if(arr[i][j+1] == '*')
				{
					++mines;
				}
				if(mines != 0)
				{
					cout << "NO";
					return 0;
				}
			}
			if(arr[i][j] >= '1' && arr[i][j] <= '8')
			{
				ll mines = 0;
				ll reqd = arr[i][j] - '0';
				rep(k,j-1,j+2)
				{
					if(arr[i-1][k] == '*')
					{
						++mines;
					}
					if(arr[i+1][k] == '*')
					{
						++mines;
					}
				}
				if(arr[i][j-1] == '*')
				{
					++mines;
				}
				if(arr[i][j+1] == '*')
				{
					++mines;
				}
				if(mines != reqd)
				{
					cout << "NO";
					return 0;
				}
			}
		}
	}
	cout << "YES";
	return 0;
}