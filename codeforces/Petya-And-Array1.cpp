//template by chamow
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define T pair<ll, ll>
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

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


ll getless(ordered_set &os, ll R, ll index)
{
	return os.order_of_key({R, index});
}

ordered_set os1;
ll ans = 0;
ll id = 1;

int main()
{
	fastread;
	ll n, t;
	cin >> n >> t;
	vec arr(n + 1, 0);
	rep(i,1,n+1)
	{
		cin >> arr[i];
		arr[i] += arr[i-1];
	}
	os1.insert(mp(0, 0));
	rep(i,1,n+1)
	{
		ans += (os1.size() - getless(os1, arr[i] - t, INF));
		os1.insert(mp(arr[i], id++));
	}
	cout << ans;
	return 0;
}