#include<bits/stdc++.h>
using namespace std;
int V,minimum=-100000,maximum=-10000;
void printSolution(int shortestDistance[])
{
    int i;
    for(i=0;i<V;i++)
    {
        maximum=max(maximum,(shortestDistance[i]));
    }
    cout<<maximum<<endl;
    minimum=max(minimum,maximum);
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

void Dijkstras(int adjMatrix[500][500],int s)
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
    printSolution(shortestDistance);

}

int main()
{
    int t,u,n,m,v,i,j,s,distance;
    while(t--)
    {
        cin>>V>>m;
    int adjMatrix[500][500];
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            adjMatrix[i][j]=0;
        }
    }
   for(i=0;i<m;i++)
    {
        cin>>u>>v;
        cin>>distance;
        adjMatrix[u][v]=distance;
        adjMatrix[v][u]=distance;

    }
    for(i=0;i<V;i++)
    Dijkstras(adjMatrix,i);
    cout<<minimum<<endl;

    }

}
