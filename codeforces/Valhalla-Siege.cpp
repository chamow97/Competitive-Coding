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

const ll MAXN = 1e5 + 100;
vec prefix(MAXN+1, 0);
vec prefix1(MAXN+1, 0);
int main()
{
	fastread;
	ll q, n;
	cin >> n >> q;
	prefix1.resize(q+1);
	prefix.resize(n+1);
	rep(i,1,n+1)
	{
		ll val;
		cin >> val;
		prefix[i] = prefix[i-1] + val;
	}
	ll prev = 0;
	rep(i,1,q+1)
	{
		ll val;
		cin >> val;
		prefix1[i] = val;		
	}
	ll old = 0;
	rep(i,1,q+1)
	{
		ll val = prefix1[i];
		val += old;
		old += prefix1[i];
		if(lower_bound(prefix.begin(), prefix.end(), val) == prefix.end())
		{
			old = 0;
			cout << n << '\n';
		}
		else
		{
			ll pos = lower_bound(prefix.begin(), prefix.end(), val) - prefix.begin();
			ll extra = prefix[pos] - val;
			if(extra == 0)
			{
				if(pos == n)
				{
					old = 0;
					pos = 0;
				}
				cout << n - pos << '\n';

			}
			else
			{
				cout << n - pos + 1 << '\n';
				// old += extra;
			}
		}
	}
	return 0;
}