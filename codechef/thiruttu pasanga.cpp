#include<stdio.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n,count=0;
        int i,j,k;
        scanf("%d",&n);

        int a[n];

        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j && a[i]!=0)
                {
                    if(a[i]==a[j])
                    {
                        ++count;
                        for(k=j;k<n;k++)
                        {
                            if(a[k]==a[i])
                                a[k]=0;
                        }



                    }
                }
            }
        }

        printf("%d\n",count);
    }

}
