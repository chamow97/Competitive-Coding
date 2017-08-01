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
	fastread;
	ll n, k;
	string str;
	cin>>n>>k;
	cin>>str;
	vector< pair<ll, ll> > v;
	rep(i,0,26)
	{
		ll start = -1, end = -1;
		rep(j,0,n)
		{
			if(str[j] - 'A' == i)
			{
				if(start == -1)
				{
					start = j;
				}
				end = j;
			}
		}
		if(start == -1)
		{
			continue;
		}
		v.pb(mp(start,end));
	}
	ll now = 0;
	ll maximum = 0;
	ll reduce = 0;
	rep(i,0,n)
	{
		rep(j,0,v.size())
		{
			if(reduce == 1)
			{
				--now;
				reduce = 0;
			}
			if(v[j].first == i)
			{
				++now;
			}
			if(v[j].second == i)
			{
				++reduce;
			}
			maximum = max(maximum, now);
		}
		// cout<<now<<" ";
		
	}
	if(maximum > k)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}