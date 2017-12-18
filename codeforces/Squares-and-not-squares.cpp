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
	vec arr(n,0);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	vec squares;
	rep(i,0,100000)
	{
		squares.pb(i*i);
	}
	vecpair p;
	rep(i,0,n)
	{
		ll diff1 = upper_bound(squares.begin(), squares.end(), arr[i]) - squares.begin();
		if(diff1 != 0)
		{
			--diff1;
		}	
		diff1 = squares[diff1];
		ll diff2 = *upper_bound(squares.begin(), squares.end(), arr[i]);
		p.pb(mp(min(abs(diff1 - arr[i]), abs(diff2 - arr[i])), arr[i]));
	}
	sort(p.begin(), p.end());
	ll extra = 0;
	rep(i,0,n/2)
	{
		extra += p[i].first;
	}
	rep(i,n/2,n)
	{
		if(p[i].first == 0 && p[i].second == 0)
		{
			extra += 2;
		}
		else if(p[i].first == 0)
		{
			extra++;
		}
	}
	cout << extra;
	return 0;
}
