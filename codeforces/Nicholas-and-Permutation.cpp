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
	cin>>n;
	vec arr(n,0);
	rep(i,0,n)
	{
		cin>>arr[i];
	}
	ll maximum = 0;
	rep(i,0,n)
	{
		rep(j,i+1,n)
		{
			vec newArr(n,0);
			rep(k,0,n)
			{
				if(k == i)
				{
					newArr[k] = arr[j];
				}
				else if(k == j)
				{
					newArr[k] = arr[i];
				}
				else
				{
					newArr[k] = arr[k];
				}
			}
			ll pos1 = 0, pos2 = 0;
			rep(k,0,n)
			{
				if(newArr[k] == 1)
				{
					pos1 = k;
				}
				else if(newArr[k] == n)
				{
					pos2 = k;
				}
			}
			maximum = max(maximum, abs(pos1 - pos2));
		}
	}
	cout<<maximum;
	return 0;
}
