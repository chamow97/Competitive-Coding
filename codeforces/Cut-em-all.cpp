#include<bits/stdc++.h>
using namespace std;

#define pb push_back
const int MAXN = 1e5 + 100;
vector<int> adj[MAXN];
vector<bool> visited(MAXN, false);
vector<int> curr(MAXN, 1);
vector<int> ans(MAXN, 0);

void dfs(int s)
{
	visited[s] = true;
	for(auto i : adj[s])
	{
		if(!visited[i])
		{
			dfs(i);
			curr[s] += curr[i];
			if(curr[i] % 2 == 0)
			{
				ans[s]++;
			}
			ans[s] += ans[i];
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}	
	if(n % 2 == 1)
	{
		cout << -1;
	}
	else
	{
		dfs(1);
		if(ans[1] != 0 || curr[1] == n)
		{
			cout << ans[1];
		}
		else
		{
			cout << -1;
		}
	}
}