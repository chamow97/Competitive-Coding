#include<stdio.h>

using namespace std;
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        long int n,m,pos=0,i,j,k;
        scanf("%ld %ld",&n,&m);
        long int a[n][m];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%ld",&a[i][j]);
            }
        }
        for(k=0;k<n*m;k++)
        {


        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if((i+j)==pos)
                {
                    printf("%ld ",a[i][j]);
                }
            }
        }
        pos++;

        }
        printf("\n");


    }

}
