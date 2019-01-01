#include<bits/stdc++.h>

using namespace std;

int main()
{
	//Each diameter has 2 leaf nodes
	//If we increase some non-leaf node, it will decrease leaf node's value
	//but eventually add up to diameter
	//so distribute the sum among the leaf and put 0 in non-leaf nodes
	int n, s;
	cin >> n >> s;
	vector<int> adj[n + 1];
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int leaf = 0;
	for(int i = 1; i <= n; i++)
	{
		if(adj[i].size() == 1)
		{
			++leaf;
		}
	}
	long double ans = 0.0;
	ans = 2 * ((s * 1.00) / (leaf * 1.00));
	cout << setprecision(15) << ans;
	return 0;
}