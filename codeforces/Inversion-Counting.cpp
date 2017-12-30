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

ll calcInversion(vec arr)
{
	ll counter = 0;
	ll n = arr.size();
	rep(i,0,n)
	{
		rep(j,i+1,n)
		{
			if(arr[j] < arr[i])
			{
				++counter;
			}
		}
	}
	return counter;
}

int main()
{
	fastread;
	//thx to PrashantM for the observation
	ll n;
	cin >> n;
	vec arr(n,0);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	ll cur = calcInversion(arr);
	cur %= 2;
	ll m;
	cin >> m;
	while(m--)
	{
		ll l, r;
		cin >> l >> r;
		--l;
		--r;
		ll counter = r - l + 1;
		if(counter == 1)
		{
			
		}
		else
		{
			ll val = (counter * (counter - 1))/2;
			val %= 2;
			if(cur == 1 && val == 1)
			{
				cur = 0;
			}
			else if(cur == 0 && val == 1)
			{
				cur = 1;
			}
			else if(cur == 1 && val == 0)
			{
				cur = 1;
			}
			else if(cur == 0 && val == 0)
			{
				cur = 0;
			}
		}
		if(cur == 0)
		{
			cout << "even\n";
		}
		else
		{
			cout << "odd\n";
		}
	}
	return 0;
}
