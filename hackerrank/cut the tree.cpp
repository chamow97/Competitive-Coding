#include<bits/stdc++.h>
#define pb push_back
using namespace std;
list<int> *adj = new list<int>[100001];
bool visited[100001];
long long i,n,sum=0,minimum=INT_MAX;
long long a[100001],arr[100001];
long long dfs(long s)
{
	if(visited[s]==true)
		return 0;
	if(adj[s].size()==1)
	{
		arr[s]=a[s];
		visited[s]=true;
		return arr[s];
	}
	else
	{
		list<int>::iterator it;
		visited[s]=true;
		int c=a[s];
		for(it=adj[s].begin();it!=adj[s].end();++it)
		{
			int k=(*it);
			c+=(dfs(k));
		}
		arr[s]=c;
		return arr[s];

	}
}
int main()
{
	long long  root,u,v;
	cin>>n;

	for(i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=(a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		cin>>u>>v;
		u-=1;
		v-=1;
		adj[u].pb(v);
		adj[v].pb(u);

	}
	for(i=0;i<n;i++)
	{
		visited[i]=false;
		arr[i]=0;
	}
	for(i=0;i<n;i++)
	{
		if(adj[i].size()>1)
        {
            root=i;
            break;
        }
	}
	int  c=dfs(root);
	for(i=0;i<n;i++)
	{
		minimum=min(minimum,abs(sum-(2*arr[i])));
	}
	cout<<minimum;

}
