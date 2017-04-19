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

/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;

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
	string s;
	cin>>s;
	ll len = s.length();
	s += " ";
	rep(i,1,len)
	{
		if(s[i] == s[i-1])
		{
			if(s[i] == 'z' || s[i] == 'y')
			{
				if(s[i] - 1 == s[i+1])
				{
					s[i] = s[i] - 2;
				}
				else
				{
					s[i] = s[i] - 1;
				}
			}
			else
			{
				if(s[i] + 1 == s[i+1])
				{
					s[i] = s[i] + 2;
				}
				else
				{
					s[i] = s[i] + 1;
				}
			}
		}
	}

	cout<<s;
	return 0;
}