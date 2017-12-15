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
	ll t, n, m;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		vector<string> str(n+10);
		rep(i,0,n)
		{
			string str1;
			cin >> str1;
			str[i] = str1;
		}
		ll minimum = INF;
		ll value = 0;
		rep(i,0,n)
		{
			rep(j,0,m)
			{
				if(i % 2 == 0)
				{
					if(j % 2 == 0)
					{
						if(str[i][j] != 'R')
						{
							value += 3;
						}
					}
					else
					{
						if(str[i][j] != 'G')
						{
							value += 5;
						}
					}
				}
				else
				{
					if(j % 2 == 0)
					{
						if(str[i][j] != 'G')
						{
							value += 5;
						}
					}
					else
					{
						if(str[i][j] != 'R')
						{
							value += 3;
						}
					}

				}
			}
		}

		minimum = min(minimum, value);
		value = 0;
		rep(i,0,n)
		{
			rep(j,0,m)
			{
				if(i % 2 == 0)
				{
					if(j % 2 == 0)
					{
						if(str[i][j] != 'G')
						{
							value += 5;
						}
					}
					else
					{
						if(str[i][j] != 'R')
						{
							value += 3;
						}
					}
				}
				else
				{
					if(j % 2 == 0)
					{
						if(str[i][j] != 'R')
						{
							value += 3;
						}
					}
					else
					{
						if(str[i][j] != 'G')
						{
							value += 5;
						}
					}

				}
			}
		}
		minimum = min(minimum, value);
		cout << minimum << '\n';
	}
	return 0;
}
