#include<stdio.h>

using namespace std;

int main()
{

    int t;
    long int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld",&n);
        long int k;
        int count=0,i,j;
        int a[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        scanf("%ld",&k);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if((a[i]*a[j])==k)
                    {

                     ++count;
                    }
                }
            }
        }

    printf("%d\n",count/2);
    }

}
