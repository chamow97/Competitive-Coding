#include<stdio.h>


using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long int n,count=0,i;
        scanf("%ld",&n);
        long int a[n];
        for(i=0;i<n;i++)
        {
            scanf("%ld",&a[i]);
        }
        for(i=0;i<n-1;i++)
        {
            if(a[i]<a[i+1])
            {
                count+=(a[i+1]-a[i]);
                a[i+1]=(a[i+1]-(a[i+1]-a[i]));
            }
        }
        printf("%ld\n",count);
    }
}
