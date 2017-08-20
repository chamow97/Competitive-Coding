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
		ll k, a, b;
		cin>>k>>a>>b;
		ll minimum = min(a,b);
		ll maximum = max(a,b);
		a = minimum;
		b = maximum;
		ll mid = k/2;
		if(k%2 == 0)
		{
			if((b-a) == mid)
			{
				cout<<0<<'\n';
				continue;
			}
		}
		ll val1 = (b-a-1);
		ll val2 = (k - val1 - 2);
		cout<<min(val1, val2)<<'\n';
	}
	return 0;
}