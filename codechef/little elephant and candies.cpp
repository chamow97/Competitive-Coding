#include<stdio.h>

using namespace std;

int main()
{
    long int t,i;
    scanf("%ld",&t);
    for(i=0;i<t;i++)
    {
        long int n,c,j,sum=0;
        scanf("%ld %ld",&n,&c);
        long int a[n];
        for(j=0;j<n;j++)
        {
            scanf("%ld",&a[j]);
            sum+=a[j];
        }
        if(sum>c)
        {
            printf("No\n");

        }
        else if(sum<=c)
        {
            printf("Yes\n");
        }

    }
}
