#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a[100000],i,m,j;
    cin>>t;
    while(t--)
    {
      cin>>m;
      cin>>n;
      for(i=0;i<n;i++)
      {
          cin>>a[i];
      }
      for(i=0;i<n;i++)
      {
          for(j=0;j<n;j++)
          {
              if(i!=j)
              {
                  if(a[i]+a[j]==m)
                  {
                      cout<<min(i+1,j+1)<<' '<<max(i+1,j+1)<<endl;
                      break;
                  }
              }
          }
      }

    }
}
