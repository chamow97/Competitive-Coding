#include<stdio.h>

using namespace std;

int main()
{
    long int n,i,sum=0,j=0,sum1=0,sum2=0;
    scanf("%ld",&n);
    int a[n],b[n],c[n];
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
    }
    for(i=0;i<n;i++)
    {
        sum+=(a[i]);

    }
    sum1=b[0]+c[0];
    sum2=b[0]+c[0]+a[0];
    for(i=1;i<n;i++)
    {
        if(sum1>=(b[i]+c[i]))
            sum1=b[i]+c[i];

    }
    for(i=1;i<n;i++)
    {
        if(sum2<=(b[i]+c[i]))
            if((b[i]+c[i])>=sum)
            sum2=(b[i]+c[i]+a[i]);
    }

    if(sum1>=sum2)
    printf("%ld",sum+sum1);
    else if(sum1<=sum2)
        printf("%ld",sum2);
}
