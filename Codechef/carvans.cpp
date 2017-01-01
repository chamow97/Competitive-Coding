#include<stdio.h>

using namespace std;

int main()
{


    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        int n,count=1;
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<n;i++)
        {
            if(a[i]>a[i-1])
                a[i]=a[i-1];
        }
        for(i=1;i<n;i++)
        {
            if(a[i]<a[i-1])
                ++count;
        }

        printf("%d\n",count);
    }

}
