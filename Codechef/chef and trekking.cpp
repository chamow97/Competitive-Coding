#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
    int j,i,d[111];
    bool visited[111];
    vector<int> *vec;
    int n,m,k,u,v;
    cin>>k;
    vec = new vector<int>[111];
    for(i=1;i<=100;i++)
    {
        d[i] = INT_MAX;
        visited[i] = false;
    }
    for(i=1;i<=100;i++)
    {
        for(j=i+1;j<=k+i;j++)
        {
            vec[i].pb(j);
        }
    }
    cin>>m>>n;
    while(m--)
    {
        cin>>u>>v;
        vec[u].pb(v);
    }
    while(n--)
    {
        cin>>u>>v;
        vec[u].pb(v);
    }
    d[1] = 0;
    visited[1] = true;
    for(i=1;i<=100;i++)
    {
        vector<int>::iterator it;
        for(it=vec[i].begin();it!=vec[i].end();it++)
        {
            if(visited[*it]==false && d[*it] > (1+d[i]))
            {
                d[*it] = 1+d[i];
            }
        }
    }
//    for(i=1;i<=100;i++)
//    {
//        cout<<d[i]<<endl;
//    }
    cout<<d[100];
}
