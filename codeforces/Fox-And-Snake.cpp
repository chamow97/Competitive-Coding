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
	char maze[n+100][m+100];
	rep(i,0,n+100)
	{
		rep(j,0,m+100)
		{
			maze[i][j] = '.';
		}
	}
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			if(i % 2 == 1)
			{
				maze[i][j] = '#';
			}
		}
	}
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			if(i % 4 == 2 && j == m)
			{
				maze[i][j] = '#';
			}

			if(i % 4 == 0 && j == 1)
			{
				maze[i][j] = '#';
			}
		}
	}
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			cout << maze[i][j];
		}
		cout << '\n';
	}

	return 0;
}
