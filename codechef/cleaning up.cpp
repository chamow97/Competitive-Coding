#include<stdio.h>

using namespace std;

int main()
{
    int t,i;
    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        int n,m,j,k,b[1000],value=-1;
        scanf("%d %d",&n,&m);
        int a[m+1];
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[j]);
        }

        for(k=1;k<=n;k++)
            b[k]=k;
        j=0;

        while(j<m)
        {


        for(k=1;k<=n;k++)
        {

            if(b[k] == a[j])
            {
                b[k]=0;

            }

        }
        ++j;
        }


        for(k=1;k<=n;k++)
        {

            if(b[k]!=0)
            {
                value=(value*(-1));
                if(value == 1)
                {
                    b[k]=1;
                }
                else if(value == -1)
                {
                    b[k]=-1;
                }

            }
        }
        for(k=1;k<=n;k++)
        {
            if(b[k] == 1)
            {
                printf("%d ",k);
            }

        }
        printf("\n");
        for(k=1;k<=n;k++)
        {
            if(b[k] == -1)
            {
                printf("%d ",k);
            }
        }
        printf("\n");


    }
}
