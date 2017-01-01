#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i,t,m,n,a[100000],counter=0,k;
    cin>>t;
    while(t--)
    {
        k=0;
        counter=0;
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            cin>>a[i];
        }
        sort(a,a+m);

          while(counter<m)
          {
              if(a[k]==0)
                ++k;
            if(a[k]==1 && counter==m-2)
            {
                counter++;
                --m;
            }
            else if(a[k]==1)
            {
                counter++;
                k-=2;
            }
            else
            {
                a[k]=a[k]-1;
                counter+=1;
            }
          }

        cout<<counter;
    }
}
