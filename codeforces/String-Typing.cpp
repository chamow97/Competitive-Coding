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
	ll n, maximum = 0;
	cin >> n;
	string str;
	cin >> str;
	vec freq[26];
	rep(i,0,n)
	{
		freq[str[i] - 'a'].pb(i);
	}
	// rep(i,0,n)
	{
		ll ptr = -1;
		for(auto j : freq[str[0] - 'a'])
		{
			if(j > 0)
			{
				ptr = j;
				ll ptr1 = 0;
				ll ptr2 = ptr;
				ll counter = 0;
				while(ptr1 < ptr && ptr1 < n && ptr2 < n)
				{
					if(str[ptr1] == str[ptr2])
					{
						++counter;
					}
					else
					{
						break;
					}
					ptr1++;
					ptr2++;
				}
				
				// cout << ptr1 << ' ' << ptr;
				if(ptr1 != ptr)
				{
					
				}
				else
				{
					maximum = max(maximum, counter);
				}
			}
		}
	}
	cout << min(n, n - maximum + 1);
	return 0;
}