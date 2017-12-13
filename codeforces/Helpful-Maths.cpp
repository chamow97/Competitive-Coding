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
	ll ones = 0, twos = 0, threes = 0;
	rep(i,0,str.length())
	{
		if(str[i] == '1')
		{
			++ones;
		}
		else if(str[i] == '2')
		{
			++twos;
		}
		else if(str[i] == '3')
		{
			++threes;
		}
	}
	rep(i,0,ones-1)
	{
		cout << "1+";
	}
	if((twos > 0 || threes > 0) && ones > 0)
	{
		cout << "1+";
	}
	else if(ones > 0)
	{
		cout << "1";
	}
	rep(i,0,twos-1)
	{
		cout << "2+";
	}
	if(threes > 0 && twos > 0)
	{
		cout << "2+";
	}
	else if(twos > 0)
	{
		cout << "2";
	}
	rep(i,0,threes - 1)
	{
		cout << "3+";
	}
	if(threes > 0)
	cout << "3";
	return 0;
}
