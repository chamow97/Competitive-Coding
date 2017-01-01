#include<stdio.h>

using namespace std;


int main()
{
    int n,k,i,j,t,pos,flag=0,ride=0;
    long int m;

    scanf("%d %d %ld",&n,&k,&m);
    long int a[n],b[n];

    for(i=0;i<n;i++)
    {
        scanf("%ld %ld",&a[i],&b[i]);
    }
    long int max=(a[0]-b[0]);
    while(k--)
    {
        for(i=0;i<n;i++)
        {
            if(a[i]!=0 )
            {

            flag=1;

            if(max<(a[i]-b[i]))
                {max=a[i]-b[i];
                pos=i;
                }


            }
            if(flag==1)
            {

            k-=b[pos];
            ++ride;
            flag=0;
            }

        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    while(k!=0)
    {
        for(i=0;i<n;i++)
        {
            if(a[i]!=0)
            {
             k-=a[i];
             ++ride;
            }
        }
    }

    printf("%d\n",ride);
}
