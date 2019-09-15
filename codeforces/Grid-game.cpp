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
	ll h = 0, v = 0;
	rep(i,0,str.length())
	{
		if(str[i] == '0')
		{
			if(h == 0)
			{
				cout << 1 << ' ' << 1;
			}
			else
			{
				cout << 3 << ' ' << 1;
			}
			h++;
		}
		else
		{
			if(v == 0)
			{
				cout << 1 << ' ' << 2;
			}
			else if(v == 1)
			{
				cout << 2 << ' ' << 2;
			}
			else if(v == 2)
			{
				cout << 3 << ' ' << 2;
			}
			else if(v == 3)
			{
				cout << 4 << ' ' << 2;
			}
			v++;
		}
		cout << '\n';
		h %= 2;
		v %= 4;
	}
	return 0;
}