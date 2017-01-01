#include<bits/stdc++.h>
using namespace std;
#define pb push_back
class graph
{
    long long V,i,m;
   // long long **adj;
    long long j;
    bool visited[3000];
    long long key[3000];
    long long parent[3000];
    long long adj[1000][1000];
public:
    graph(long long n,long long W)
    {
       V=n;
       m=W;

     // long long adj[][] = new long long adj[V][V];
        for(i=0;i<V;i++)
        {
            key[i]=1000000;
            parent[i]=0;
            visited[i]=false;
        }
        for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                adj[i][j]=0;
            }
        }
    }
    void addedge(long long,long long,long long);
    void Prims(long long);
    long long findminimum();
};
void graph :: addedge(long long u,long long v,long long cost)
{
    adj[u-1][v-1]=cost;
    adj[v-1][u-1]=cost;
}
void graph :: Prims(long long s)
{

    long long counter=0;
    key[0]=1000000;
    //parent[0]=-1;
    for(i=0;i<V;i++)
    {
        long long u=findminimum();
        visited[u]=true;
        for(j=0;j<V;j++)
        {
            if(visited[j]==false && key[j]>adj[u][j] && adj[u][j])
            {

                key[j]=adj[u][j];
                //parent[j]=u;
            }
        }
    }
    for(i=1;i<V;i++)
    {
        if(key[i]!=1000000)
        counter+=key[i];
    }
    cout<<counter<<endl;
}
long long graph :: findminimum()
{
    long long minimum=1000000,pos=-1;
    for(long long k=0;k<V;k++)
    {
        if(minimum>key[k] && visited[k]==false)
        {
            minimum=key[k];
            pos=k;
        }
    }

    return pos;
}
int main()
{
    long long s,i,n,m,u,v,cost;
    cin>>n>>m;
    graph G(n,m);
    for(i=0;i<m;i++)
    {
        cin>>u>>v>>cost;
        G.addedge(u,v,cost);
    }
    cin>>s;
    s-=1;
    G.Prims(s);

}
