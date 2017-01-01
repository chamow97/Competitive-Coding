#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
    int j,i,d[10001];
    bool visited[10001];
    vector<int> *vec;
    int n,m,k,u,v;
    cin>>n>>m;
    vec = new vector<int>[10001];
    for(i=1;i<=m*2;i++)
    {
        d[i] = INT_MAX;
        visited[i] = false;
    }
    vec[1].pb(2);
    for(i=2;i<=m*2;i++)
    {
            vec[i].pb(i-1);
            vec[i].pb(i*2);
    }
   d[n] = 0;
    visited[n] = true;
    for(i=n;i<=m;i++)
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
    cout<<d[m];
}
 