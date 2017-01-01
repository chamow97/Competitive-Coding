#include<stdio.h>

using namespace std;

long int pal(long int a)
{
    long int t,temp,pal=0;
    temp=a;
    while(a)
    {
        t=a%10;
        a/=10;
        pal=(pal*10)+t;
    }
    if(temp == pal)
        return 1;
    else
        return 0;

}


int main()
{
    long int n,t,palin;
    long int i,j,k;

    scanf("%ld",&t);
    for(i=0;i<t;i++)
    {
        int largest=10000;
        scanf("%ld",&n);

        for(j=999;j>=100;j--)
        {
            for(k=999;k>=100;k--)
            {
                if(j*k<=n)
                {

                    if( pal(j*k)==1)
                       {
                         if(j*k>=largest)
                            largest=j*k;
                       }

                }
            }
        }
        printf("%ld\n",largest);
    }

}
