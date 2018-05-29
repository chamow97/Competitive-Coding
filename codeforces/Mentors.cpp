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

bool myFunc(const pair<ll, ll> &p1, const pair<ll, ll> &p2)
{
	return p1.f < p2.f;
}

int main()
{
	fastread;
	ll n, k;
	cin >> n >> k;
	vecpair arr(n+1);
	vec brr(n+1);
	rep(i,1,n+1)
	{
		cin >> brr[i];
		arr[i].f = brr[i];
		arr[i].s = i; 
	}
	sort(arr.begin(), arr.end());
	vec adj[n+1];
	rep(i,1,k+1)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep(i,1,n+1)
	{
		ll ctr = 0;
		for(auto j : adj[i])
		{
			if(brr[j] < brr[i])
			{
				ctr++;
			}
		}
		ll pos = lower_bound(arr.begin(), arr.end(), mp(brr[i], 0), myFunc) - arr.begin();
		pos--;
		pos -= ctr;
		cout << pos << ' ';
	}
	return 0;
}