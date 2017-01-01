#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long s,t,a,b,n,m,temp,i,apples=0,oranges=0;
    cin>>s>>t;
    cin>>a>>b;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        if((a+temp)>=s && (a+temp)<=t)
            ++apples;
    }
      for(i=0;i<m;i++)
    {
        cin>>temp;
        if((b+temp)>=s && (b+temp)<=t)
            ++oranges;
    }
    cout<<apples<<endl<<oranges;
}
