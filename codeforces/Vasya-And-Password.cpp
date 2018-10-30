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

bool isLow(char a)
{
	return (a >= 'a' && a <= 'z');
}
bool isHigh(char a)
{
	return (a >= 'A' && a <= 'Z');
}
bool isDigit(char a)
{
	return (a >= '0' && a <= '9');
}

int main()
{
	fastread;
	ll t;
	cin >> t;
	while(t--)
	{
		string str;
		cin >> str;
		ll n = str.length();
		ll low = 0, high = 0, digit = 0;
		rep(i,0,n)
		{
			if(isLow(str[i]))
			{
				low++;
			}
			else if(isHigh(str[i]))
			{
				high++;
			}
			else
			{
				digit++;
			}
		}
		if(low > 0 && high > 0 && digit > 0)
		{
			
		}
		else if(low == 0 && high > 0 && digit > 0)
		{
			if(high > 1)
			{
				rep(i,0,n)
				{
					if(isHigh(str[i]))
					{
						str[i] = 'a';
						break;
					}
				}
			}
			else
			{
				rep(i,0,n)
				{
					if(isDigit(str[i]))
					{
						str[i] = 'a';
						break;
					}
				}
			}
		}
		else if(high == 0 && low > 0 && digit > 0)
		{
			if(low > 1)
			{
				rep(i,0,n)
				{
					if(isLow(str[i]))
					{
						str[i] = 'A';
						break;
					}
				}
			}
			else
			{
				rep(i,0,n)
				{
					if(isDigit(str[i]))
					{
						str[i] = 'A';
						break;
					}
				}
			}
		}
		else if(high > 0 && low > 0 && digit == 0)
		{
			if(low > 1)
			{
				rep(i,0,n)
				{
					if(isLow(str[i]))
					{
						str[i] = '0';
						break;
					}
				}
			}
			else
			{
				rep(i,0,n)
				{
					if(isHigh(str[i]))
					{
						str[i] = '0';
						break;
					}
				}
			}
		}
		else if(high == 0 && low == 0 && digit > 1)
		{
			ll count = 0;
			rep(i,0,n)
			{
				if(count == 2)
				{
					break;
				}
				if(isDigit(str[i]) && count == 0)
				{
					str[i] = 'a';
					++count;
				}
				else if(isDigit(str[i]) && count == 1)
				{
					str[i] = 'A';
					++count;
				}
			}
		}
		else if(high > 1 && low == 0 && digit == 0)
		{
			ll count = 0;
			rep(i,0,n)
			{
				if(count == 2)
				{
					break;
				}
				if(isHigh(str[i]) && count == 0)
				{
					str[i] = 'a';
					++count;
				}
				else if(isHigh(str[i]) && count == 1)
				{
					str[i] = '0';
					++count;
				}
			}
		}
		else if(high == 0 && low > 1 && digit == 0)
		{
			ll count = 0;
			rep(i,0,n)
			{
				if(count == 2)
				{
					break;
				}
				if(isLow(str[i]) && count == 0)
				{
					str[i] = 'A';
					++count;
				}
				else if(isLow(str[i]) && count == 1)
				{
					str[i] = '0';
					++count;
				}
			}
		}
		cout << str << '\n';
	}
	return 0;
}