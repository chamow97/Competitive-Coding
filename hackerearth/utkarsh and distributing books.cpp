#include<stdio.h>

using namespace std;

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n,j,min,count=0;
        scanf("%d",&n);
        int a[n];
        for(j=0;j<n;j++)
        scanf("%d",&a[j]);
        min=a[0];
        for(j=1;j<n;j++)
        {
            if(min>a[j])
                min=a[j];
        }
        for(j=0;j<n;j++)
        {
            count+=(a[j]-1);
        }

        printf("%d %d\n",min-1,count);

    }
}
