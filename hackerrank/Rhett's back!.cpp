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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vec arr(n,0);
		rep(i,0,n)
		{
			cin>>arr[i];
		}
		if(n == 1 || n == 2)
		{
			cout<<1<<'\n';
		}
		else
		{
			vec longestTill(n,0);
			vec valueTill(n,0);
			rep(i,0,n)
			{
				longestTill[i] = 1;
				valueTill[i] = arr[i];
			}
			rep(i,2,n)
			{
				rep(j,0,i-1)
				{
					if((arr[i] >= valueTill[j]))
					{
						longestTill[i] = max(longestTill[i], longestTill[j] + 1);
						if(longestTill[i] == longestTill[j] + 1)
						{
							valueTill[i] = max(valueTill[j],  arr[i]);
						}
					}
				}
			}
			ll maxSize = 0;
			rep(i,0,n)
			{
				maxSize = max(maxSize, longestTill[i]);
			}
			cout<<maxSize<<'\n';
		}

	}
	return 0;
}
