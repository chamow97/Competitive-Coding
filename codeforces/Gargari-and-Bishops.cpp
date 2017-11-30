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
	ll maze[n+10][n+10];
	vec diagonal(3 * n, 0);
	vec diagonal2(3 * n, 0);
	rep(i,0,n)
	{
		rep(j,0,n)
		{
			cin >> maze[i][j];
			diagonal[i+j] += maze[i][j];
			diagonal2[i-j+n] += maze[i][j];
		}
	}
	ll maxDiag1 = 0, maxDiag2 = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 1;
	rep(i,0,n)
	{
		rep(j,0,n)
		{
			if((i + j) % 2 == 0)
			{
				if(diagonal[i+j] + diagonal2[i-j+n] - maze[i][j] > maxDiag1)
				{
					maxDiag1 = diagonal[i+j] + diagonal2[i-j+n] - maze[i][j];
					x1 = i;
					y1 = j;
				}
			}
			else
			{
				if(diagonal[i+j] + diagonal2[i-j+n] - maze[i][j] > maxDiag2)
				{
					maxDiag2 = diagonal[i+j] + diagonal2[i-j+n] - maze[i][j];
					x2 = i;
					y2 = j;
				}

			}
		}
	}

	cout << maxDiag1 + maxDiag2 << '\n';
	cout << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1;

	return 0;
}
