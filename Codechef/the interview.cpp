#include<stdio.h>

using namespace std;

int main()
{
    int t,i,j,x,y,x1,y1,val,n;
    long int sum=0,m,l;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %ld",&n,&m);
        int a[n][n];
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
        for(l=0;l<m;l++)
        {
            char b[2];
            scanf("%s",b);
            if(b[0]=='Q')
                {

                scanf("%d %d %d %d",&x,&y,&x1,&y1);
                for(i=x-1;i<x1;i++)
                for(j=y-1;j<y1;j++)
                   sum+=a[i][j];
                printf("%ld\n",sum);
                sum=0;

                }
            else
            {


                scanf("%d %d %d",&x,&y,&val);
                a[x-1][y-1]=val;

            }


         }

   }

 }

