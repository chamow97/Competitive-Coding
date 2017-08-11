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


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;


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
ll counter = 0;
void solve(ll n, vector< pair<ll, ll> > *adj, ll s, boolean &visited, vec &ans)
{
	if(counter == n)
	{
		return;
	}
	
		visited[s] = true;
		++counter;
	
	vector< pair<ll, ll> >:: iterator it;
	for(it = adj[s].begin(); it != adj[s].end(); it++)
	{
		ll v = (*it).first;
		ll w = (*it).second;
		if(visited[v] == false)
		{
			ans[v] += (ans[s] + w);
			solve(n, adj, v, visited, ans);
		}
	}
}

int main()
{
	/*
	Logic: we try to go to the path with maximum weight only once greedily 
	which means that we go to every other path twice.... So ans = (longest path weight) + (2*other path)
	in DFS
	*/
	fastread;
	ll n;
	cin>>n;
	ll solution = 0;
	vector< pair<ll, ll> > *adj = new vector< pair<ll, ll > > [n];
	ll x, y, t;
	rep(i,0,n-1)
	{
		cin>>x>>y>>t;
		x--;y--;
		adj[x].pb(mp(y,t));
		adj[y].pb(mp(x,t));
		solution += (t*2);
	}
	vec ans(n,0);
	boolean visited(n,false);
	solve(n, adj, 0ll, visited, ans);
	ll maximum = 0;
	rep(i,0,n)
	{
		maximum = max(maximum, ans[i]);
	}
	solution -= maximum;
	cout<<solution;
	return 0;
}