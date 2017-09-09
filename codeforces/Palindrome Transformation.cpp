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

ll difference(char a, char b)
{
	return min(abs(a-b), min(abs(26+a-b), abs(b+26-a)));
}

ll extra(ll l, ll r, ll k)
{
	if(l == -1 && r == -1)
	{
		return 0;
	}
	if(l == -1)
	{
		return (abs(r-k));
	}
	if(r == -1)
	{
		return (abs(k-l));
	}
	ll a = abs(k-l) + abs(r-l);
	ll b = abs(r-k) + abs(l-r);
	return min(a,b);
}

int main()
{
	fastread;
	ll n, k;
	cin>>n>>k;
	k = min(k, n-k+1);
	--k;
	string str;
	cin>>str;
	ll solution = 0;
	rep(i,0,n)
	{
		if(str[i] != str[n-i-1])
		{
			solution += difference(str[i], str[n-1-i]);
		}
	}
	solution /= 2;
	ll l = -1, r = -1;
	rep(i,0,n/2)
	{
		if(str[i] != str[n-i-1])
		{
			if(i < k &&  l == -1)
			{
				l = i;
			}
			if(i > k)
			{
				r = max(r, i);
			}
		}
	}
	solution += (extra(l,r,k));
	cout<<solution;
	return 0;
}