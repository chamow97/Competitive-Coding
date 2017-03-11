#include<bits/stdc++.h>
using namespace std;
int V;
void printSolution(int shortestDistance[],int s)
{
    for(int i=0;i<V;i++)
    {
            if(i!=s)
            {
                if(abs(shortestDistance[i])==INT_MAX || shortestDistance[i]<0)
                shortestDistance[i]=-1;
            cout<<shortestDistance[i]<<' ';
            }


    }
    cout<<endl;
}
int minDistance(int shortestDistance[],bool visited[])
{
    int i,distance=INT_MAX;
    int index;
    for(i=0;i<V;i++)
    {
        if(!visited[i]&&shortestDistance[i]<=distance)
        {
            distance=shortestDistance[i];
            index = i;
        }
    }
    return index;
}

void Dijkstras(int adjMatrix[1000][1000],int s)
{
    bool visited[V];
    int shortestDistance[V];
    int i;
    for(i=0;i<V;i++)
    {
        visited[i]=false;
        shortestDistance[i]=INT_MAX;
    }
    shortestDistance[s]=0;
    for(i=0;i<V-1;i++)
    {
        int u=minDistance(shortestDistance,visited);
        visited[u]=true;
        for(int v=0;v<V;v++)
        {
            if(!visited[v] &&
                shortestDistance[v]!=0 &&
                 adjMatrix[u][v]!=0 &&
                 shortestDistance[v]>shortestDistance[u]+adjMatrix[u][v] )
            {
                shortestDistance[v]=shortestDistance[u]+adjMatrix[u][v];
            }
        }
    }
    printSolution(shortestDistance,s);

}

int main()
{
    int q,m,u,v,s,i,j;
    cin>>q;
    while(q--)
    {
        cin>>V>>m;
        int adj[1000][1000];
        for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                adj[i][j]=0;
            }
        }
        for(i=0;i<m;i++)
        {
            cin>>u>>v;
            adj[u-1][v-1]=6;
            adj[v-1][u-1]=6;

        }
         cin>>s;
        Dijkstras(adj,s-1);
    }


}
