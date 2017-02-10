//template by chamow

#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
typedef long long ll;
ll readInt () {
	bool minus = false;
	ll result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
ll n,m,u,v;
	bool isTree = true;
	list<int> *adj;

void dfs(ll s, bool visited[])
{
	visited[s] = true;
	list<int>::iterator it;
	for(it = adj[s].begin(); it != adj[s].end(); it++)
	{
		if(visited[*it] == false)
		{
			dfs(*it, visited);
		}
	}
}
int main()
{
	n = readInt();
	m = readInt();
	adj = new list<int>[n];
	rep(i,0,m)
		{
			cin>>u>>v;
			u -= 1;
			v -= 1;
			adj[u].pb(v);
			adj[v].pb(u);
		}
	if(m == n-1)
	{
		
		
		bool visited[n];
		rep(i,0,n)
		{
			visited[i] = false;
		}
		//svisited[0] = 0;
		dfs(0, visited);
		rep(i,0,n)
		{
			if(visited[i] != true)
			{
				isTree = false;
				break;
			}
		}

	}
	else
	{
		isTree = false;
	}
	if(isTree == true)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
    return 0;
}
