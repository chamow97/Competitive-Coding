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
	cin >> str;
	vec freq(26, 0);
	rep(i,0,str.length())
	{
		freq[str[i] - 'a']++;
	}
	ll unique = 0, unique1 = 0;
	rep(i,0,26)
	{
		if(freq[i] > 0)
		{
			unique1++;
		}
		if(freq[i] >= 2)
		{
			++unique;
		}
	}
	if(unique1 == 1 || unique1 > 4 || str.length() <= 3)
	{
		cout << "No";
		return 0;
	}
	if(unique1 == 2)
	{
		if(unique >= 2)
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
		return 0;
	}
	if(unique1 == 3 || unique1 == 4)
	{
		cout << "Yes";
		return 0;
	}
	return 0;
}