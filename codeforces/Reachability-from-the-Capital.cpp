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

const int MAXN = 5e3 + 10;
vec adj[MAXN];
boolean visited(MAXN, false);
map<int, int> m1;
int n, m, s;
vec bad;
int counter = 0;

void dfs(int st)
{
	m1[st]++;
	visited[st] = true;
	for(auto i : adj[st])
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}
}

void badDfs(int st)
{
	++counter;
	visited[st] = true;
	for(auto i : adj[st])
	{
		if(!visited[i] && m1[i] < 1)
		{
			badDfs(i);
		}
	}
}

int main()
{
	fastread;
	cin >> n >> m >> s;
	m1[s]++;
	rep(i,1,m+1)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}
	dfs(s);
	vecpair ans;
	counter = 0;
	rep(i,1,n+1)
	{
		if(m1[i] < 1)
		{
			bad.pb(i);
		}
	}
	for(auto i : bad)
	{
		fill(visited.begin(), visited.end(), false);
		badDfs(i);
		ans.pb(mp(counter, i));
		counter = 0;
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	fill(visited.begin(), visited.end(), false);
	int answer = 0;
	for(auto i : ans)
	{
		if(!visited[i.s])
		{
			answer++;
			dfs(i.s);
		}
	}
	cout << answer;
	return 0;
}