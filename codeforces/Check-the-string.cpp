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
	string str;
	cin >> str;
	ll n = str.length();
	vec freq(35, 0);
	rep(i,0,n)
	{
		freq[str[i] - 'a']++;
	}
	string str1 = str;
	sort(str1.begin(), str1.end());
	rep(i,0,n)
	{
		if(str[i] != str1[i])
		{
			cout << "NO";
			return 0;
		}
	}
	if(freq[1] > 0 && freq[0] > 0 && freq[2] > 0)
	{
		if(freq[2] == freq[1] || freq[2] == freq[0])
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
	}
	else
	{
		cout << "NO";
	}
	return 0;
}