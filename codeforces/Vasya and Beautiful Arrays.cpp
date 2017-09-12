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
	vec arr(n,0);
	vec frequency(2000001,0);
	rep(i,0,n)
	{
		cin>>arr[i];
		frequency[arr[i]]++;
	}
	rep(i,1,2000001)
	{
		frequency[i] += frequency[i-1];
	}
	ll maximum = 1;
	rep(i,1,2000001)
	{
		ll counter = 0;
		for(ll j = i; j <= 2000000-i; j += i)
		{
			counter += (frequency[j+min(k,i-1)] - frequency[j-1]);
		}
		if(counter == n)
		{
			maximum = max(maximum, i);
		}
	}
	cout<<maximum;

	return 0;
}