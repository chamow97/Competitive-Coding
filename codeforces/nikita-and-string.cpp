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
	string str;
	cin>>str;
	ll n = str.length();
	vec posA(n+1,0), posB(n+1,0);
	rep(i,0,n)
	{
		if(str[i] == 'a')
		{
			posA[i+1] = 1;
		}
	}
	rep(i,0,n)
	{
		if(str[i] == 'b')
		{
			posB[i+1] = 1;
		}
	}
	rep(i,1,n+1)
	{
		posA[i] += posA[i-1];
	}
	rep(i,1,n+1)
	{
		posB[i] += posB[i-1];
	}
	ll maximum = 0;
	rep(i,1,n+1)
	{
		rep(j,i+1,n+1)
		{
			ll current = posA[i] + (posB[j] - posB[i]) + (posA[n] - posA[j]);
			maximum = max(maximum, current);
		}
	}
	maximum = max(posA[n], maximum);
	maximum = max(posB[n], maximum);
	rep(i,1,n+1)
	{
		ll current = (posB[i] - posB[0]) + (posA[n] - posA[i]);
		maximum = max(maximum, current);
	}
	rep(i,1,n+1)
	{
		ll current = (posA[i] - posA[0]) + (posB[n] - posB[i]);
		maximum = max(maximum, current);
	}
	cout<<maximum;
	return 0;
}
