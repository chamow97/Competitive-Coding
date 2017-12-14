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
	ll cases = 0;
	while(1)
	{
		++cases;
		string str;
		cin >> str;
		if(str[0] == '-')
		{
			break;
		}
		ll ans = 0;
		ll extra = 0, remaining = 0;
		rep(i,0,str.length())
		{
			if(str[i] == '{')
			{
				++extra;
			}
			else
			{
				--extra;
				if(extra < 0)
				{
					extra = 1;
					remaining++;
				}
			}
		}
		
		cout << cases << ". " <<  remaining + (extra)/2 << '\n';
	}
	return 0;
}
