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

ll R, x, x2, y2, y, xCoord, yCoord;

ll findPosition()
{
	xCoord = pow(x2 - x, 2);
	yCoord = pow(y2 - y, 2);
	ll lhs = xCoord + yCoord;
	ll rhs = R*R;
	if(lhs < rhs)
	{
		return 0ll;
	}
	if(lhs == rhs)
	{
		return 1ll;
	}
	return 2ll;
}

int main()
{
	fastread;
	cin >> R >> x >> y >> x2 >> y2;
	if(x == x2 && y == y2)
	{
		double xNew = x + R;
		double yNew = y;
		double xMid = (xNew + x)/2;
		double yMid = (yNew + y)/2;
		double Radius = sqrt(pow(xMid - x, 2) + pow(yMid - y, 2));
		cout << setprecision(12) << xMid << ' ' << yMid << ' ' << Radius; 
		return 0;
	}
	ll pos = findPosition();
	if(pos > 0)
	{
		cout << x << ' ' << y << ' ' << R;
	}
	else
	{
		double xIntersection = 0.0, yIntersection = 0.0, xVal1, xVal2, yVal1, yVal2;
		xIntersection = sqrt((R*R*1.00)/(1*1.00 + ((yCoord * 1.00)/(xCoord * 1.00))));
		yIntersection = sqrt((R*R*1.00)/(1*1.00 + ((xCoord * 1.00)/(yCoord * 1.00))));
		xVal1 = x - xIntersection;
		xVal2 = x + xIntersection;
		yVal1 = y - yIntersection;
		yVal2 = y + yIntersection;
		double xMid1 = ((x2 * 1.00) + xVal1)/(2.00);
		double xMid2 = ((x2 * 1.00) + xVal2)/(2.00);
		double yMid1 = ((y2 * 1.00) + yVal1)/(2.00);
		double yMid2 = ((y2 * 1.00) + yVal2)/(2.00);
		double R1 = sqrt(pow(xMid1 - x2, 2) + pow(yMid1 - y2, 2));
		double R2 = sqrt(pow(xMid2 - x2, 2) + pow(yMid2 - y2, 2));
		double R3 = sqrt(pow(xMid1 - x2, 2) + pow(yMid2 - y2, 2));
		double R4 = sqrt(pow(xMid2 - x2, 2) + pow(yMid1 - y2, 2));
		double maxR = max(R1, max(R2, max(R3, R4)));
		if(R1 == maxR)
		cout << setprecision(12) << xMid1 << ' ' << yMid1 << ' ' << maxR;
		else if(R2 == maxR)
		cout << setprecision(12) << xMid2 << ' ' << yMid2 << ' ' << maxR;
		else if(R3 == maxR)
		cout << setprecision(12) << xMid1 << ' ' << yMid2 << ' ' << maxR;
		else
		cout << setprecision(12) << xMid2 << ' ' << yMid1 << ' ' << maxR;
	}
	return 0;
}