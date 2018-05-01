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

int main()
{
	fastread;
	ll n, m;
	cin >> n >> m;
	vec adj[n+10];
	rep(i,0,m)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	map<ll, ll> m1;
	rep(i,1,n+1)
	{
		m1[adj[i].size()]++;
	}
	ll oneCount = m1[1];
	ll twoCount = m1[2];
	ll nCount = m1[m];
	if(nCount == 1 && oneCount == m)
	{
		cout << "star topology";
	}
	else if(twoCount == n)
	{
		cout << "ring topology";
	}
	else if(twoCount == n - 2 && oneCount == 2)
	{
		cout << "bus topology";
	}
	else
	{
		cout << "unknown topology";
	}
	return 0;
}