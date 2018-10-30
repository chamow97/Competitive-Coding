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
	cin >> n;
	if(n == 1)
	{
		cout << 1;
		return 0;
	}
	vec arr(n + 1, 0);
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	vec left(n + 1, 0);
	vec right(n + 1, 0);
	left[1] = 1;
	rep(i,2,n+1)
	{
		if(arr[i] > arr[i - 1])
		{
			left[i] = left[i - 1] + 1;
		}
		else
		{
			left[i] = 1;
		}
	}
	right[n] = 1;
	per(j,n-1,1)
	{
		if(arr[j] < arr[j + 1])
		{
			right[j] = right[j + 1] + 1;
		}
		else
		{
			right[j] = 1;
		}
	}
	ll ans = max(left[n - 1] + 1, right[2] + 1);
	rep(i,2,n)
	{
		if(arr[i + 1] - arr[i - 1] > 1)
		{
			ans = max(ans, left[i - 1] + 1 + right[i + 1]);
		}
		else
		{
			ans = max(ans, left[i - 1] + 1);
			ans = max(ans, right[i + 1] + 1);
		}
	}
	cout << ans;
	return 0;
}