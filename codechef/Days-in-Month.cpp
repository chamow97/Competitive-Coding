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
	ll t;
	cin >> t;
	while(t--)
	{
		ll days;
		string start;
		cin >> days >> start;
		char arr[100][100] = {"mon", "tues", "wed", "thurs", "fri", "sat" , "sun", "mon", "tues", "wed", "thurs", "fri", "sat" , "sun" };
		ll val = -1;
		ll each = days/7;
		ll extra = days % 7;
		map<string, ll> m;
		if(start == "mon")
		{
			val = 0;
		}
		if(start == "tues")
		{
			val = 1;
		}
		if(start == "wed")
		{
			val = 2;
		}
		if(start == "thurs")
		{
			val = 3;
		}
		if(start == "fri")
		{
			val = 4;
		}
		if(start == "sat")
		{
			val = 5;
		}
		if(start == "sun")
		{
			val = 6;
		}
		rep(i,val,val+extra)
		{
			m[arr[i]] = 1;
		}
		rep(i,0,7)
		{
			cout << m[arr[i]] + each << " ";
		}
		cout << '\n';

	}
	return 0;
}
