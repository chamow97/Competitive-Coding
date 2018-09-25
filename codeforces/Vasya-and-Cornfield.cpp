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


long double area(int x1, int y1, int x2, int y2,
                            int x3, int y3)
{
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + 
                x3 * (y1 - y2)) / 2.0);
}
 
/* A function to check whether point P(x, y) 
   lies inside the rectangle formed by A(x1, y1), 
   B(x2, y2), C(x3, y3) and D(x4, y4) */
bool check(int x1, int y1, int x2, int y2, int x3, 
             int y3, int x4, int y4, int x, int y)
{
    /* Calculate area of rectangle ABCD */
    long double A = area(x1, y1, x2, y2, x3, y3) + 
              area(x1, y1, x4, y4, x3, y3);
 
    /* Calculate area of triangle PAB */
    long double A1 = area(x, y, x1, y1, x2, y2);
 
    /* Calculate area of triangle PBC */
    long double A2 = area(x, y, x2, y2, x3, y3);
 
    /* Calculate area of triangle PCD */
    long double A3 = area(x, y, x3, y3, x4, y4);
 
    /* Calculate area of triangle PAD */
    long double A4 = area(x, y, x1, y1, x4, y4);
 
    /* Check if sum of A1, A2, A3 and A4 
       is same as A */
    // cout << A << ' ' << A1 << ' ' << A2 << ' ' << A3 << ' ' << A4;
    return (A == A1 + A2 + A3 + A4);
}

int main()
{
	fastread;
	int n, d;
	cin >> n >> d;
	int m;
	cin >> m;
	while(m --)
	{
		int x, y;
		cin >> x >> y;
		if(check(0, d, d, 0,n, n - d, n - d, n, x, y))
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
		cout << '\n';
	}
	return 0;
}