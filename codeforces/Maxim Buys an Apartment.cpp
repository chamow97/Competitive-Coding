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

int main()
{
	fastread;
	ll n, k;
	cin>>n>>k;
	ll minimum = 0, maximum = 0;
	if(n == k || k == 0)
	{
		minimum = 0;
		maximum = 0;
	}
	else if(k == 1 && n == 2)
	{
		minimum = 1;
		maximum = 1;
	}
	else if(k == 1)
	{
		minimum = 1;
		maximum = 2;
	}
	else
	{
		minimum = 1;
		maximum = min(2*k, n-k);
	}
	cout<<minimum<<" "<<maximum;


	return 0;
}