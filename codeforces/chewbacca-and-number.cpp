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
	ll n;
	cin>>n;
	string ans = "";
	while(n >= 10)
	{
		ll t = n % 10;
		n /= 10;
		if(t <= 4)
		{
			ans += (t + '0');
		}
		else
		{
			ans += ((9 - t) + '0');
			
		}
	}
	ll t = n % 10;
	if(t == 9 || t <= 4)
	{
		ans += (t + '0');
	}
	else
	{
		ans += ((9 - t) + '0');
	}
	for(auto it = ans.rbegin(); it != ans.rend(); it++)
	{
		cout<<*it;
	}
	return 0;
}
