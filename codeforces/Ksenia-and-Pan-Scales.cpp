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
	string str, str1;
	cin >> str;
	ll before = 0, after = 0, found = 0;
	rep(i,0,str.length())
	{
		if(str[i] != '|')
		{
			if(found == 0)
			{
				++before;
			}
			else
			{
				++after;
			}
		}
		else
		{
			found = 1;
		}
	}
	cin >> str1;
	ll extra = str1.length();
	extra -= (abs(before - after));
	if(extra < 0)
	{
		cout << "Impossible";
		return 0;
	}
	else
	{
		if(extra % 2 != 0)
		{
			cout << "Impossible";
			return 0;
		}
		extra /= 2;
		if(before <= after)
		{
			ll pos = -1;
			rep(i,0,str.length())
			{
				if(str[i] == '|')
				{
					pos = i;
					break;
				}
				else
				{
					cout << str[i];
				}
			}
			rep(i,0,(after - before))
			{
				cout << str1[i];
			}
			rep(i,(after - before),(after - before) + extra)
			{
				cout << str1[i];
			}
			rep(i,pos,str.length())
			{
				cout << str[i];
			}
			rep(i,(after - before)+extra, str1.length())
			{
				cout << str1[i];
			}
		}
		else
		{
			ll pos = -1;
			rep(i,0,str.length())
			{
				if(str[i] == '|')
				{
					pos = i;
					break;
				}
				else
				{
					cout << str[i];
				}
			}
			rep(i,0,extra)
			{
				cout << str1[i];
			}
			rep(i,pos,str.length())
			{
				cout << str[i];
			}
			rep(i,extra,str1.length())
			{
				cout << str1[i];
			}
		}
	}
	return 0;
}
