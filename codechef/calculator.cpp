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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n, b;
		cin>>n>>b;
		ll current = 0;
		--n;
		current = 1;
		if(b > n)
		{
			cout<<0<<'\n';
		}
		else
		{
			ll remainder = n%b;
			current += remainder;
			n -= remainder;
			ll possible = n/b;
			if(possible % 2 == 1)
			{
				ll temp = (possible + 1)/2;
				current += ((possible - temp)*b);
				cout<<(current * temp)<<'\n';
			}
			else
			{
				ll ans = 0;
				ll temp = (possible + 1)/2;
				current += ((possible - temp)*b);
				ans = max(ans, current*temp);
				current -= ((possible - temp)*b);
				temp = (possible/2);
				current += ((possible - temp)*b);
				ans = max(ans, current*temp);
				cout<<ans<<'\n';
			}
		}

	}
	return 0;
}