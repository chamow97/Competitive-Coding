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

ll n;
const ll MAXN = 2e5 + 20;
vec adj[MAXN];
vec parent(MAXN, 0);
boolean visited(MAXN, false);

void dfs(ll s)
{
	visited[s] = true;
	for(auto i : adj[s])
	{
		if(!visited[i])
		{
			parent[i] = s;
			dfs(i);
		}
	}
}

int main()
{
	fastread;
	cin >> n;
	rep(i,2,n + 1)
	{
		ll val;
		cin >> val;
		adj[val].pb(i);
		adj[i].pb(val);
	}
	dfs(1);
	ll dest = n;
	vec ans;
	while(dest != 0)
	{
		ans.pb(dest);
		dest = parent[dest];
	}
	reverse(ans.begin(), ans.end());
	for(auto i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}