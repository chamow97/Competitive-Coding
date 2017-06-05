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

ll countDigitSum(ll mid)
{
	ll counter = 0;
	ll temp;
	while(mid != 0)
	{
		temp = mid % 10;
		mid /= 10;
		counter += temp;
	}
	return counter;
}

int main()
{
	fastread;
	ll n, s;
	cin>>n>>s;
	ll low = 0, high = n;
	ll mid;
	while(low <= high)
	{
		mid = (low + high + 1)/2;
		ll counter = countDigitSum(mid);
		if((mid - counter) >= s)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
		// cout<<low<<high<<endl;
	}
	// cout<<low;
	cout<<n-low+1;
	return 0;
}