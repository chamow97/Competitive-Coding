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

ll getDigitSum(ll n)
{
	ll sum = 0;
	while(n)
	{
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}

int main()
{
	fastread;
	ll n;
	ll arr[] = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 9999999999, 99999999999, 999999999999};
	cin >> n;
	ll maximum = getDigitSum(n);
	if(n <= 10)
	{
		cout << n;
	}
	else
	{
		rep(i,0,12)
		{
			if(n - arr[i] < 0)
			{
				break;
			}
			maximum = max(maximum, ll(getDigitSum(arr[i]) + getDigitSum(n - arr[i])));
		}
		cout << maximum;
	}
	return 0;
}