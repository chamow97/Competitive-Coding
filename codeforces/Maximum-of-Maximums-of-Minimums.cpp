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
	ll n, k;
	cin>>n>>k;
	ll maxPos = -1;
	ll maximum = -INF;
	ll minimum = INF;
	vec arr(n,0);
	rep(i,0,n)
	{
		cin>>arr[i];
		minimum = min(minimum,arr[i]);
		if(arr[i] > maximum)
		{
			maximum = arr[i];
			maxPos = i;
		}
	}
	if(k == 1)
	{
		cout<<minimum;
	}
	else if(k == 2)
	{
		cout<<max(arr[0], arr[n-1]);
	}
	else
	{
		cout<<maximum;
	}

	return 0;
}
