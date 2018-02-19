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
	ll maximum = 0;
	vec arr(n+1,0);
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	vec prefix(n+10, 0);
	vec suffix(n+10, 0);
	rep(i,1,n+1)
	{
		if(arr[i] == 1)
		{
			prefix[i] = 1 + prefix[i-1];
		}
		else
		{
			prefix[i] = prefix[i-1];
		}
	}
	per(j,n,1)
	{
		if(arr[j] == 2)
		{
			suffix[j] = 1 + suffix[j+1];
		}
		else
		{
			suffix[j] = suffix[j+1];
		}
	}
	//understood how dumb I am while solving this. 
	rep(i,1,n+1)
	{
		ll max1 = 0, max2 = 0;
		//we should know what max we can get from the interval
		rep(j,i,n+1)
		{
			//if arr[j] == 2, then just increment
			if(arr[j] == 2)
			{
				max2 += 1;
			}
			else 
			{
				// if there are already some twos, then we shld take that into account as well
				max1 = max(max1, max2) + 1;
			}
			maximum = max(maximum, prefix[i-1] + suffix[j+1] + max(max1, max2));
		}
	}
	cout << maximum;

	return 0;
}