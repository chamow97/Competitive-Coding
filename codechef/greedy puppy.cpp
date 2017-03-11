#include<stdio.h>

using namespace std;

int main()
{
    int j,i,max,n,k;
    long int t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&n,&k);
        int max=0;
        for(j=2;j<=k;j++)
        {
            if(n%j>max)
                max=n%j;
        }
        printf("%d\n",max);
    }
}
