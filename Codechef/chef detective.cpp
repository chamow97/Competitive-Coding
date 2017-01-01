#include<stdio.h>

using namespace std;

int main()
{
    long int n,i,j;
    scanf("%ld",&n);
    long int a[n];
    int flag=0;
    for(i=0;i<n;i++)
    {
        scanf("%ld",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        flag=0;
        for(j=0;j<n;j++)
        {
            if(i==a[j])
            {
                flag=1;
                break;
            }
            else
            {
                flag=0;
            }
        }
        if(flag==0)
        {
            printf("%ld ",i);
        }
    }




}
