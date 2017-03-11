#include<bits/stdc++.h>
using namespace std;
#define pb push_back
long long t,n,m,u,v,cost[3000][],c,s;
list<int>*adj;
void dijkstras(int s)
{

}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        adj=new list<int>[n];
        for(i=0;i<m;i++)
        {
            cin>>u>>v>>c;
            u-=1;
            v-=1;
            adj[u].pb(v);
            adj[v].pb(u);
            cost[u][v]=c;
            cost[v][u]=c;
        }
        cin>>s;
        dijkstras(s);
    }
}
