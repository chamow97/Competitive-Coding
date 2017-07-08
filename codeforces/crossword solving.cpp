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
	ll n, m;
	string s, t;
	cin>>n>>m;
	cin>>s>>t;

	ll matches = 0;
	ll ans = INF;
	vec finalpos;
	
	rep(i,0,m-n+1)
	{
		matches = 0;
		vec pos;
		rep(j,0,n)
		{
			if(t[i+j] != s[j])
			{
				++matches;
				pos.pb(j+1);
			}
		}
		if(ans > matches)
		{
			ans = matches;
			finalpos = pos;
		}

	}
	cout<<ans<<'\n';
	rep(i,0,finalpos.size())
	{
		cout<<finalpos[i]<<" ";		
	}
	return 0;
}