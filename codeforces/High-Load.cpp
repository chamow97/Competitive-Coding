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
	ll n, k;
	cin >> n >> k;
	ll depth = (n - 1) / k;
	ll modVal = (n - 1) % k;
	if(modVal == 0)
	{
		cout << 2 * depth;
	}
	else if(modVal == 1)
	{
		cout << 2 * depth + 1;
	}
	else
	{
		cout << 2 * (depth + 1);
	}
	cout << '\n';
	ll root = 1;
	ll ptr = 2;
	while(ptr <= k + 1)
	{
		cout << root << ' ' << ptr << '\n';
		ptr++;
	}
	while(ptr <= n)
	{
		root = ptr - k;
		rep(i,0,k + 1)
		{
			cout << root << ' ' << ptr << '\n';
			root++;
			ptr++;
			if(ptr > n)
			{
				break;
			}
		}	
	}
	return 0;
}	