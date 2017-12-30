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
	ll n, r;
	cin >> n >> r;
	vec arr(n,0);
	long double brr[20000] = {0.0};
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	//saw editorial
	rep(i,0,n)
	{
		long double maximum = r;
		ll center = arr[i];
		rep(j,0,i)
		{
			long double d = abs(arr[i] - arr[j]);
			if(d <= (2*r))
			{
				maximum = max(maximum, brr[j] + sqrt((4 * r * r * 1.00) - (d * d * 1.00)));		
			}
		}
		
		brr[i] = (maximum);	
		cout << setprecision(15) << brr[i] << ' ';
	}
	return 0;
}
