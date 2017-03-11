#include<stdio.h>

using namespace std;
int main()
{
    int t,i;
    scanf("%ld",&t);

    for(i=0;i<t;i++)
    {
        long int n,j,k,t,summax=0;

        scanf("%ld",&n);
        long int a[n];

        for(j=0;j<n;j++)
        {
            scanf("%ld",&a[j]);
        }
        for(j=0;j<n;j++)
        {
            for(k=0;k<n-1-i;k++)
            {
                if(a[k]<a[k+1])
                {
                    t=a[k];
                    a[k]=a[k+1];
                    a[k+1]=t;
                }
            }
        }

        for(j=0;j<n-1;j++)
        {
            summax+=(a[j]+a[j+1]);
            a[j+1]=(a[j]+a[j+1]);
        }

        printf("%ld\n",summax);


    }
}
