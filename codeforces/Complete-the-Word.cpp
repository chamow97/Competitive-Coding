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
	ll n = str.length();
	if(n < 26)
	{
		cout << -1;
		return 0;
	}
	ll ptr = 0;
	bool possible = true;
	while(ptr + 25 < n)
	{
		ll extra = 0;
		set<char> s;
		rep(i,0,26)
		{
			if(str[i + ptr] == '?')
			{
				++extra;
			}
			else
			{
				s.insert(str[i + ptr]);
			}
		}
		if(s.size() + extra == 26)
		{
			break;
		}
		ptr++;
	}
	if(ptr + 25 == n)
	{
		cout << -1;
		return 0;
	}
	set<ll> s;
	rep(i,0,26)
	{
		if(str[i + ptr] != '?')
		s.insert((str[i + ptr] - 'A'));
	}
	rep(i,0,26)
	{
		if(str[i + ptr] == '?')
		{
			rep(j,0,26)
			{
				if(s.find(j) == s.end())
				{
					str[i + ptr] = (j + 'A');
					s.insert(j);
					break;
				}
			}
		}
	}
	rep(i,0,n)
	{
		if(str[i] == '?')
		{
			str[i] = 'A';
		}
	}
	cout << str;
	return 0;
}