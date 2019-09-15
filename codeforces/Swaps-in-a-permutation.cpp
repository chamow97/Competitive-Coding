#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 100;
int n, m;
vector<pair<int, int>> arr(MAXN);
vector<bool> visited(MAXN, false);
vector<int> adj[MAXN];
vector<int> vec;
vector<int> pos;
vector<int> ans(MAXN, 0);

void dfs(int s)
{
	visited[s] = true;
	vec.push_back(arr[s].second);
	pos.push_back(arr[s].first);
	for(auto i : adj[s])
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i].second;
		arr[i].first = i;
	}
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= n; i++)
	{
		if(!visited[i])
		{
			vec.resize(0);
			pos.resize(0);
			dfs(i);
			sort(vec.begin(), vec.end(), greater<int>());
			sort(pos.begin(), pos.end());
			for(int i = 0; i < vec.size(); i++)
			{
				ans[pos[i]] = vec[i];
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}