#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main()
{
	int sum=0,n,m,i,u,v,counter[100];
	bool visited[100];
	vector<int> *adj;
	cin>>n>>m;
	for(i=0;i<100;i++)
	{
		counter[i]=0;
		visited[i]=false;
	}
	vector<int>::iterator it;
	adj = new vector<int>[n];
	for(i=0;i<m;i++)
	{
		cin>>u>>v;
		u-=1;
		v-=1;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(i=n-1;i>=0;i--)
	{
		if(adj[i].size()==1)
		{
			counter[i]=1;
			visited[i]=true;
		}
	}
	for(i=n-1;i>=0;i--)
	{
		if(visited[i]==false)
		{
			for(it=adj[i].begin();it!=adj[i].end();it++)
			{
					counter[i]+=(counter[*it]);
					visited[i]=true;				
			}
			counter[i]+=1;
		}		
		
	}
	for(i=1;i<n;i++)
	{
		if(counter[i]%2==0)
		{
			++sum;
		}
	}
	cout<<sum<<endl;
}