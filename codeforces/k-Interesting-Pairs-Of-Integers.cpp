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
const ll maxn = 1e5;
ll n, k;
vec freq(maxn, 0);
vec arr(maxn);
vec ans(maxn, 0);
int main()
{
	fastread;
	cin >> n >> k;
	rep(i,0,n)
	{
		cin >> arr[i];
		freq[arr[i]]++;
	}
	ll counter = 0;
	rep(i,0,1e4+1)
	{
		if(freq[i] > 0)
		{
			rep(j,i,1e4+1)
			{
				if(freq[j] == 0)
				{
					continue;
				}
				ll now = i ^ j;
				if(__builtin_popcount(now) == k)
				{
					if(i == j)
					{
						counter += ((freq[i] * (freq[i] - 1))/2);
						continue;
					}
					counter += ((freq[i] * freq[j]));
				}
			}
		}
	}
	cout << counter;
	return 0;
}