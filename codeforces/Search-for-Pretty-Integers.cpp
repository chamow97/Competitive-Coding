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
	ll n, m;
	vec arr1(10,0);
	vec arr2(10,0);
	cin>>n>>m;
	ll minimum = INF;
	rep(i,0,n)
	{
		cin>>arr1[i];
	}
	rep(i,0,m)
	{
		cin>>arr2[i];
	}
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			if(arr1[i] == arr2[j])
			{
				minimum = min(minimum, arr1[i]);
			}
		}
	}
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			ll curr = arr1[i]*10 + arr2[j];
			minimum = min(minimum, curr);
		}
	}

	rep(i,0,m)
	{
		rep(j,0,n)
		{
			ll curr = arr2[i]*10 + arr1[j];
			minimum = min(minimum, curr);
		}
	}
	cout<<minimum;
}
