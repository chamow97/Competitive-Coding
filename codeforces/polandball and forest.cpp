//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157

/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;

/*-------------------------------------------------------- */

void dfs(ll s, vector<int> *adj, boolean &visited)
{
	visited[s] = true;
	vector<int> :: iterator it;
	for(it = adj[s].begin(); it != adj[s].end(); it++)
	{
		if(visited[*it] == false)
		{
			dfs(*it, adj, visited);
		}
	}
}

int main()
{
	ll n, temp, counter = 0;
	cin>>n;
	vector<int> *adj = new vector<int>[n];
	rep(i,0,n)
	{
		cin>>temp;
		--temp;
		adj[i].pb(temp);
		adj[temp].pb(i);
	}
	boolean visited(n,false);
	rep(i,0,n)
	{
		bool isOver = true;
		if(visited[i] == false)
		{
			++counter;
			dfs(i,adj,visited);
		}		
		rep(j,0,n)
		{
			if(visited[j] == false)
			{
				isOver = false;
				break;
			}
		}
		if(isOver == true)
		{
			break;
		}
	}
	cout<<counter;
	return 0;
}