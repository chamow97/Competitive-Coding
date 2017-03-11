#include<stdio.h>

using namespace std;

int main()
{
    long int t,l;
    scanf("%ld",&t);
    for(l=0;l<t;l++)
    {
        long int i,j,b,c,n,mod;
        scanf("%ld %ld %ld",&b,&c,&n,&mod);
        long int a[n];
        a[0]=b;
        a[1]=c;
        for(j=2;j<n;j++)
        {
            a[j]=((a[j-1]+a[j-2])%mod);
        }
        long int len=0;
        long int count[n];
        for(i=0;i<n;i++)
        {
            if(a[i]!=-1)
            {


            for(j=0;j<n;j++)
            {
                if(a[i]==a[j])
                {
                    count[len]+=1;
                    a[j]=-1;

                }
            }
            ++len;
            }
        }
        long int sum=0;
        for(i=0;i<len;i++)
            {
                printf("%ld ",count[i]);
            }
    //printf("%ld",sum);

    }
}
