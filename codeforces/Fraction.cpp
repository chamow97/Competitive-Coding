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


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;


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
bool coprime(long u, long v)
{
    if (((u | v) & 1) == 0) return false;

    while ((u & 1) == 0) u >>= 1;
    if (u == 1) return true;

    do
    {
        while ((v & 1) == 0) v >>= 1;
        if (v == 1) return true;

        if (u > v) { long t = v; v = u; u = t; }
        v -= u;
    } while (v != 0);

    return false;
}
int main()
{
	fastread;
	ll n;
	cin>>n;
	vector< ll > v[1001];
	double maximum = 0.0;
	ll nr = 0;
	ll dr = 0;
	rep(i,1,1001)
	{
		for(ll j = 1; j <= sqrt(i); j++)
		{
			if(j != (i/j))
			{
				v[i].pb(j);
				v[i].pb(i/j);
			}
			else
			{
				v[i].pb(j);
			}
		}
	}
	rep(i,1,n+1)
	{
		rep(j,i+1,n+1)
		{
			if(i + j == n && i < j)
			{
				if(coprime(i,j) == true)
				{
					double val = (i*1.00)/(j*1.00);
					if(maximum < val)
					{
						maximum = val;
						nr = i;
						dr = j;
					}
				}				
			}
		}
	}
	cout<<nr<<" "<<dr;
	return 0;
}