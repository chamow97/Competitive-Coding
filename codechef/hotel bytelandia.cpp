#include<stdio.h>

using namespace std;

int main()
{

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,j,t2,t1;
        scanf("%d",&n);
        int a[n],b[n];

        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-1-i;j++)
            {
                if(b[j]>b[j+1])
                {
                    t2=a[j];
                    t1=b[j];
                    a[j]=a[j+1];
                    b[j]=b[j+1];
                    a[j+1]=t2;
                    b[j+1]=t1;
                }
            }
        }
        int count=0;
        for(i=0;i<n;i++)
        {int max=0;

            for(j=i+1;j<n;j++)
            {
                if(b[i]<=b[j] && b[i]>a[j])
                    ++max;


            }
            if(count<max)
                count=max;
        }
        printf("%d\n",count+1);
    }

}
