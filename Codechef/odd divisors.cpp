#include<stdio.h>

using namespace std;

int main()
{
    long long int t,l,r,sum=0,j,i;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d %d",&l,&r);
        for(i=l;i<=r;i++)
        {
            for(j=3;j<=i/2;j+=2)
            {
                if(i%j==0)
                    sum+=j;
            }
            if(i%2!=0)
                sum+=i;
        }
        printf("%d\n",sum);

    }
}
