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
	const ll maxn = 1e5 + 100;
	ll n, k, m;
	cin >> n >> k >> m;
	vector<string> arr;
	map<string, ll> m1;
	map<string, ll> m2;
	vec best(maxn, INF);
	rep(i,0,n)
	{
		string val;
		cin >> val;
		m1[val] = i;
		arr.pb(val);
	}
	vec cost(n, 0);
	rep(i,0,n)
	{
		cin >> cost[i];
	}
	ll group = 0;
	rep(i,0,k)
	{
		++group;
		ll sizes;
		cin >> sizes;
		rep(j,0,sizes)
		{
			ll index;
			cin >> index;
			--index;
			m2[arr[index]] = group;
			best[group] = min(best[group], cost[index]);
		}
	}
	ll ans = 0;
	rep(i,0,m)
	{
		string now;
		cin >> now;
		ans += best[m2[now]];
	}
	cout << ans;

	return 0;

}