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
	ll m, n;
	cin >> m;
	vec arr(m);
	rep(i,0,m)
	{
		cin >> arr[i];
	}
	cin >> n;
	vec price(n);
	rep(i,0,n)
	{
		cin >> price[i];
	}
	sort(arr.begin(), arr.end());
	sort(price.begin(), price.end());
	ll best = arr[0];
	ll cost = 0;
	ll step = 0;
	for(ll j = n - 1; j >= 0; j--)
	{
		if(step >= best)
		{
			step = 0;
			if(j - 1 >= 0)
			{
				j -= 1;
			}
		}
		else
		{
			step++;
			cost += price[j];
		}
	}
	cout << cost;
	return 0;
}