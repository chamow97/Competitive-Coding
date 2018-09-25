//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vecit vector<int> :: iterator
#define vecpit vector< pair<int, int> > :: iterator
#define f first
#define s second


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<int> vec;
typedef vector< pair<int, int> > vecpair;


/*-------------------------------------------------------- */
const int maxn = 1100;

vec adj[maxn];
ll ans = 0;


void dfs(ll s, boolean &visited)
{
	if(visited[s] == true)
	{
		ans = s;
		return;
	}
	visited[s] = true;
	for(auto i : adj[s])
	{
		dfs(i, visited);
	}
	visited[s] = true;
}

int main()
{
	ll n;
	cin >> n;
	vec arr(n, 0);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	rep(i,0,n)
	{
		adj[i+1].pb(arr[i]);
	}
	rep(i,1,n+1)
	{
		boolean visited(maxn, false);
		dfs(i, visited);
		cout << ans << ' ';
	}
	return 0;
}