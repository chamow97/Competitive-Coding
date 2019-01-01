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

const ll MAXN = 1e5 + 10;
const ll FINGER = 6;
bool dp[MAXN][FINGER];
vec fin(MAXN, 0);
ll n;
vec arr(MAXN + 1, 0);

bool solve(ll pos)
{
	if(pos == n)
	{
		return true;
	}
	rep(i,1,FINGER)
	{
		if(dp[pos + 1][i])
		{
			continue;
		}
		if((arr[pos] == arr[pos + 1] && fin[pos] != i) || (arr[pos] < arr[pos + 1] && fin[pos] < i) || (arr[pos] > arr[pos + 1] && fin[pos] > i))
		{
			fin[pos + 1] = i;
			dp[pos + 1][i] = 1;
			if(solve(pos + 1))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	fastread;
	cin >> n;
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	memset(dp, 0, sizeof dp);
	rep(i,1,FINGER)
	{
		if(dp[1][i] == 0)
		{
			fin[1] = i;
			if(solve(1ll))
			{
				rep(i,1,n+1)
				{
					cout << fin[i] << ' ';
				}
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}