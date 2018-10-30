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
	map<ll, ll> m1;
	map<ll, char> m2;
	ll q;
	ll lPtr = 0, rPtr = 0;
	cin >> q;
	while(q--)
	{
		char choice; ll val;
		cin >> choice >> val;
		if(choice == 'L')
		{
			m2[val] = 'L';
			m1[val] = lPtr++;
		}
		else if(choice == 'R')
		{
			m2[val] = 'R';
			m1[val] = rPtr++;
		}
		else
		{
			if(m2[val] == 'R')
			{
				cout << min(rPtr - m1[val] - 1, m1[val] + lPtr);
			}
			else
			{
				cout << min(lPtr - m1[val] - 1, rPtr + m1[val]);
			}
			cout << '\n';
		}
	}
	return 0;
}