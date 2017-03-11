#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf pop_front

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int);
    void addEdge(int,int);
    void BFS(int,int);
~Graph()
{
    delete adj;
}
};
Graph :: Graph(int V)
{
    this->V=V;
    adj = new list<int>[V+1];
}

void Graph :: addEdge(int u,int v)
{
    adj[u].pb(v);
}
void Graph :: BFS(int s,int e)
{
    bool visited[V+1];
    int a[10001],k;
    for(k=0;k<=V;k++)
        visited[k]=false;
    visited[s]=true;
    list<int> q;
    q.pb(s);
    list<int>::iterator i;
    while(!q.empty())
    {
        s=q.front();
        q.pf();
        for(i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(!visited[*i])
            {
                a[*i]=1;
                visited[*i] = true;
                q.pb(*i);
            }
        }
    }
   for(k=1;k<=V;k++)
   {
       if(a[k]==1 && k!=s)
       {
           cout<<"6 ";
       }
       else
       {
           cout<<"-1 ";
       }
   }
}

int main()
{
    int i,q,n,e,u,v,s,a[10001];
    cin>>q;
    while(q--)
    {
        cin>>n;
        Graph g(n);
        cin>>e;
        for(i=0;i<e;i++)
        {
            cin>>u>>v;
            g.addEdge(u,v);
        }
        cin>>s;
        g.BFS(s,e);
    }

}
