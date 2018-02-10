		//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define eb emplace_back
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
const ll maxn = 1e6;
set<int> s;
set< int > *adj = new set< int >[maxn];

ll dfs(ll start)
{
	ll ans = 1;
	for(set<int>::iterator it = s.begin(); it != s.end();)
	{
		if(adj[start].count(*it) == 0)
		{
			ll now = (*it);
			s.erase(*it);
			ans += dfs(now);
			it = s.lower_bound(now);
		}
		else
		{
			it++;
		}
	}
	return ans;
}

int main()
{
	fastread;
	ll n, m;
	cin >> n >> m;
	//saw the editorial
	rep(i,1,n+1)
	{
		s.insert(i);
	}
	rep(i,1,m+1)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	vec ans;
	while(s.size() != 0)
	{
		ll now = *(s.begin());
		s.erase(now);
		ans.eb(dfs(now));
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	rep(i,0,ans.size())
	{
		cout << ans[i] << ' ';
	}
	return 0;
}