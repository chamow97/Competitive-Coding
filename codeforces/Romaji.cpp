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
	string str;
	cin >> str;
	bool possible = true;
	int n = str.length();
	rep(i,0,n)
	{
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u' || str[i] == 'i')
		{

		}
		else
		{
			if(str[i] == 'n')
			{

			}
			else
			{
				if(i == n - 1 || (str[i + 1] != 'a' && str[i + 1] != 'e' && str[i + 1] != 'i' && str[i + 1] != 'o' && str[i + 1] != 'u'))
				{
					possible = false;
				}
			}
		}
	}
	if(possible)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}