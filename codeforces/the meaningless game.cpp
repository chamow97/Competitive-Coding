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
	/*
	the logic is simple... each time u either multiply by
	k or k^2. so if (a,b) is valid, then there should be 
	some numbers by which it is multiplied and those numbers
	can be collectively represented as a cube of a number. To myself- Why? Use
	ur brain u dummy. If you cannot do these kinda of sums then never
	dream of even reaching expert u brainless creep!
	*/
	ll n;
	cin>>n;
	while(n--)
	{
		ll a,b;
		cin>>a>>b;
		ll total = a*b;
		ll ans = 0;
		ll low = 1, high = 1000000;
		while(low <= high)
		{
			ll mid = (low + high)/2;
			ll val = (mid*mid*mid);
			if(val < total)
			{
				low = mid+1;
			}
			else if(val > total)
			{
				high = mid-1;
			}
			else
			{
				ans = mid;
				break;
			}
			// cout<<mid<<" ";
		}
		// cout<<ans;
		if(ans != 0 && a%ans == 0 && b%ans == 0)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}

	}
	return 0;
}