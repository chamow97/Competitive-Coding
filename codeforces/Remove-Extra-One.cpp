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
	ll correct = 0;
	cin >> n;
	vec arr(n,0);
	set<ll> s;
	vec blockCount(n+1,0);
	rep(i,0,n)
	{
		cin >> arr[i];
		auto it = lower_bound(s.begin(), s.end(), arr[i]);
		if(it == s.end())
		{
			++correct;
		}
		else
		{
			ll val = *it;
			it++;
			if(it == s.end())
			{
				blockCount[val]++;
			}
		}
		s.insert(arr[i]);
	}

	ll maximum = 0;
	ll pos = -1;
	per(j,n,1)
	{
		if(maximum <= blockCount[j])
		{
			maximum = blockCount[j];
			pos = j;
		}
	}
	cout << pos;
	return 0;
}
