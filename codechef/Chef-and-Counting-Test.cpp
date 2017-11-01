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
	ll t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		ll n = str.length();
		ll counter = 0;
		rep(i,0,n-1)
		{
			if(str[i] == str[i+1])
			{
				++counter;
			}
		}
		// cout<<counter;
		string newString = "";
		newString += str[0];
		ll now = 0;
		rep(i,1,n)
		{
			if(str[i] != str[i-1])
			{

				if(now >= 2)
				{
					counter += ((now * (now - 1))/2);
				}
				now = 0;
				newString += str[i];
			}
			else
			{
				++now;
			}
		}
		if(now >= 2)
				{
					counter += ((now * (now - 1))/2);
				}
		n = newString.length();
		// cout<<newString;
		// cout<<counter;
		ll i = 0, j = 2;
		while(j < n)
		{
			if(newString[j] == newString[i])
			{
				++counter;
			}
			i++;
			j++;
		}
		cout<<counter<<'\n';
	}
	return 0;
}	