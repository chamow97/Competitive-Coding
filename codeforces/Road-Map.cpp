#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e4 + 100;
vector<int> adj[MAXN];
vector<int> parent(MAXN, 0);

void dfs(int s, int p)
{
	parent[s] = p;
	for(auto i : adj[s])
	{
		if(i != p)
		{
			dfs(i, s);
		}
	}
}

int main()
{
	int n, r1, r2;
	cin >> n >> r1 >> r2;
	for(int i = 1; i <= n; i++)
	{
		if(i == r1)
		{
			continue;
		}
		int val;
		cin >> val;
		adj[i].push_back(val);
		adj[val].push_back(i);
	}
	dfs(r2, 0);
	for(int i = 1; i <= n; i++)
	{
		if(i != r2)
		{
			cout << parent[i] << ' ';
		}
	}
	return 0;
}