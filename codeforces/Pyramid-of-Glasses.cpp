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
	ll n, t;
	cin>>n>>t;
	// if(t > (n*(n+1))/2)
	// {
	// 	cout<<n*(n+1)/2;
	// }
	// else
	{
		double glasses[10][11][11];
		ll ctr = 0;
		rep(i,1,10001)
		{
			rep(j,1,11)
			{
				rep(k,1,11)
				{
					glasses[1][j][k] = 0;
				}
			}

		}		
		rep(i,1,t+1)
		{
			glasses[1][1][1] += 1;
			rep(j,1,10)
			{
				rep(k,1,j+1)
				{
					if(glasses[1][j][k] > 1)
					{
						double val = ((glasses[1][j][k] - 1.00));
						glasses[1][j+1][k] += ((val * 1.00)/(2.00));
						glasses[1][j+1][k+1] += ((val * 1.00)/(2.00));
						glasses[1][j][k] -= (val);
						
					}
				}
			}
		}
		rep(j,1,n+1)
		{
			rep(k,1,j+1)
			{
				// cout<<glasses[1][j][k]<<" ";
				if(glasses[1][j][k] >= 1)
				{
						++ctr;
				}
			}
			// cout<<'\n';				
		}
		cout<<ctr;
	}
	return 0;
}
