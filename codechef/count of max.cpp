#include<stdio.h>

using namespace std;

int main()
{
    int t,i;
    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        long int n,j,k,max,pos,temp;
        scanf("%ld",&n);
        long int a[n],counting[n];
        for(j=0;j<n;j++)
        {
            scanf("%ld",&a[j]);
        }
        for(j=0;j<n;j++)
        {
            temp = a[j];
            for(k=0;k<n;k++)
            {
                if(temp == a[k])
                {
                    counting[j]++;
                }
            }
        }
        max=a[j];
        for(j=n-2;j>=0;--j)
        {
            if(max>=a[j])
            {

                max=a[j];
                pos = j;
            }
        }

        printf("%ld %ld",a[pos],counting[pos]);
    }


}
