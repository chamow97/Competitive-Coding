#include<stdio.h>

using namespace std;

int main()
{

    long int t,i;
    scanf("%ld",&t);

    for(i=0;i<t;i++)
    {
        long int n,j;
        scanf("%ld",&n);

        long int a[n];
        for(j=0;j<n;j++)
            scanf("%ld",&a[j]);
        long int small = a[0],small1=a[0];

        for(j=1;j<n;j++)
        {
            if(a[j]<small)
                small = a[j];
        }
        for(j=1;j<n;j++)
        {
            if(a[j]<small1 && small!=a[j])
            {
                small1=a[j];
            }
        }
        printf("%ld\n",small+small1);
    }




}
