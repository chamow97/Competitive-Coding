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
	cin>>n>>k;
	string s;
	cin>>s;
	vec occurrence(26,0);
	rep(i,0,s.length())
	{
		occurrence[s[i] - 'a']++;
	}
	ll maximum = 0;
	rep(i,0,26)
	{
		maximum = max(maximum, occurrence[i]);
	}
	ll distinct = 0;
	rep(i,0,26)
	{
		if(occurrence[i] > k)
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}