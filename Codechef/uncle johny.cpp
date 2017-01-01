#include<stdio.h>

using namespace std;


int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        long int a[n];

        for(i=0;i<n;i++)
            scanf("%ld",&a[i]);
        int k;
        scanf("%d",&k);
        long int temp=a[k-1],t;

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
        for(i=0;i<n;i++)
        {
            if(temp==a[i])
                printf("%d\n",i+1);
        }
    }
}
