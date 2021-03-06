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
	ll n;
	cin >> n;
	vec arr(n);
	rep(i,0,n)
	{
		int value;
		cin >> value;
		arr[value - 1] = i;
	}
	// use your brain bhai
	vec isIncreasing(n, 0);
	isIncreasing[0] = 1;
	rep(i,1,n)
	{
		if(arr[i] > arr[i - 1])
		{
			isIncreasing[i] = 1 + isIncreasing[i - 1];
		}
		else
		{
			isIncreasing[i] = 1;
		}
	}
	ll maximum = *max_element(isIncreasing.begin(), isIncreasing.end());
	cout << n - maximum;
	return 0;
}