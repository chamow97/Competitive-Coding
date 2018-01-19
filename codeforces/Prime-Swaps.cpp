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
const ll maxn = 1e5 + 500;

boolean primeNumbers(maxn, true);
vec prime;

void seive()
{
	rep(i,2,maxn)
	{
		if(primeNumbers[i])
		{
			prime.pb(i);
			for(ll j = i; j < maxn; j += i)
			{
				primeNumbers[j] = false;
			}

		}
	}
}

int main()
{
	fastread;
	seive();
	ll n;
	cin >> n;
	vec arr(n+1, 0);
	vec pos(n+1, 0);
	vecpair ans;
	rep(i,1,n+1)
	{
		ll val;
		cin >> val;
		arr[i] = val;
		pos[val] = i;
	}
	rep(i,1,n+1)
	{
		while(pos[i] != i)
		{
			ll extra = pos[i] - i + 1;
			ll position = upper_bound(prime.begin(), prime.end(), extra) - prime.begin();
			--position;
			ll pos1 = pos[i] - prime[position] + 1;
			ll pos2 = pos[i];
			//swap
			ll x1 = arr[pos1];
			ll x2 = arr[pos2];
			arr[pos2] = x1;
			pos[x1] = pos2;
			arr[pos1] = x2;
			pos[x2] = pos1;
			ans.pb(mp(pos1, pos2)); 
		}
	}
	cout << ans.size() << '\n';
	rep(i,0,ans.size())
	{
		cout << ans[i].f << ' ' << ans[i].s << '\n';
	}

	return 0;
}
