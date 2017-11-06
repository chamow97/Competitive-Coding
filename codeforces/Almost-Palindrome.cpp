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
	string str;
	cin>>str;
	vector< pair< char, char > > changes;
	ll n = str.length();
	rep(i,0,n/2)
	{
		if(str[i] != str[n-i-1])
		{
			changes.pb(mp(str[i], str[n-1-i]));
		}
	}
	if(changes.size() == 2 || changes.size() == 0)
	{
		if(changes.size() == 0)
		{
			cout<<"YES";
		} 
		else
		{
			if(changes[0].f < changes[0].s)
			{
				swap(changes[0].f, changes[0].s);
			}
			if(changes[1].f < changes[1].s)
			{
				swap(changes[1].f, changes[1].s);
			}
			if(changes[0].f == changes[1].f && changes[0].s == changes[1].s)
			{
				cout<<"YES";
			}
			else
			{
				cout<<"NO";
			}
		}
	}
	else if(changes.size() == 1)
	{
		if(n % 2 == 0)
		{
			cout<<"NO";
		}
		else
		{
			if(changes[0].f == str[n/2] || changes[0].s == str[n/2])
			{
				cout<<"YES";
			}
			else
			{
				cout<<"NO";
			}
		}

	}
	else
	{
		cout<<"NO";
	}
	return 0;
}
