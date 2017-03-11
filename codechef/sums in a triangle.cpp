#include<stdio.h>

using namespace std;

int main()
{
    int i,j,k;
    int t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        int a[][1000];

        for(j=0;j<n;j++)
        {
        for(k=0;k<=j;k++)
        {
            scanf("%d",&a[j][k]);
        }
        }
        int sum=0;
        for(j=0;j<n;j++)
        {
            for(k=0;k<=j;k++)
            {
                sum+=(a[k][j]);
            }
        }

    }



}

