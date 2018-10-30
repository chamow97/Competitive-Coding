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

string solve(string str)
{
	if(str.length() % 2 == 1)
	{
		return str;
	}
	string str1 = solve(str.substr(0, str.length() / 2));
	string str2 = solve(str.substr(str.length() / 2, str.length()));
	if(str1 < str2)
	{
		return str1 + str2;
	}
	return str2 + str1;
}

int main()
{
	fastread;
	string str1, str2;
	cin >> str1 >> str2;
	// cout << solve(str1) << ' ' << solve(str2);
	if(solve(str1) == solve(str2))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}