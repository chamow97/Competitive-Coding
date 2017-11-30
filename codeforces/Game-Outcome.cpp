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
	ll maze[n+1][n+1];
	rep(i,1,n+1)
	{
		rep(j,1,n+1)
		{
			maze[i][j] = 0;
			cin >> maze[i][j];
		}
	}
	rep(i,1,n+1)
	{
		ll sum = 0;
		rep(j,1,n+1)
		{
			sum += maze[i][j];
		}
		maze[i][0] = sum;
	}
	rep(i,1,n+1)
	{
		ll sum = 0;
		rep(j,1,n+1)
		{
			sum += maze[j][i];
		}
		maze[0][i] = sum;
	}

	ll counter = 0;
	rep(i,1,n+1)
	{
		rep(j,1,n+1)
		{
			if(maze[i][0] < maze[0][j])
			{
				++counter;
			}
		}
	}
	cout << counter;
	return 0;
}
