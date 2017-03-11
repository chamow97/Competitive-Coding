#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i,t,m,n,a[100000],counter=0,k;
    scanf("%lli",&t);
    while(t--)
    {
        k=0;
        counter=0;
    scanf("%lli%lli",&n,&m);
        for(i=0;i<m;i++)
        {
            cin>>a[i];
        }
        sort(a,a+m);
        m=m-1;
          while(m>0)
          {
             if(a[k]==1 )
            {
                k++;
                counter++;
                m-=2;
            }

            else
            {
                a[k]=a[k]-1;
                counter+=1;
                m-=1;
            }
          }

        printf("%lli\n",counter);
    }
}
