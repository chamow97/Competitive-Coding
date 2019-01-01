#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


const int MAXN = 2e5 + 100;
vector<int> parent(MAXN, 0);
int root = 0;
int n;
vector<int> visited(MAXN, 0);
int changeNode;
int T = 0;

void dfs(int s)
{
	if(visited[s] == T)
	{
		changeNode = s;
		return;
	}
	if(!visited[s])
	{
		visited[s] = T;
		dfs(parent[s]);
	}
}

main()
{
	fastread
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> parent[i];
		if(parent[i] == i)
		{
			root = i;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(!visited[i])
		{
			++T;
			changeNode = -1;
			dfs(i);
			if(changeNode != -1)
			{
				if(!root)
				{
					root = changeNode;
					parent[changeNode] = changeNode;
					++ans;
				}
				if(root != changeNode)
				{
					++ans;
					parent[changeNode] = root;
				}
			}
		}
	}
	cout << ans << '\n';
	for(int i = 1; i <= n; i++)
	{
		cout << parent[i] << ' ';
	}
	return 0;	
}