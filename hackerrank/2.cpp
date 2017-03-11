#include<stdio.h>

using namespace std;

int main()
{
    long int a=-1,b=1,c,t,n,sum=0;

    scanf("%ld",&t);

    for(long int i=0;i<t;i++)
    {
        scanf("%ld",&n);

        for(;;)
            {c=a+b;
            if(c>n)
                break;
            a=b;
            b=c;

            if(c>0 && c%2 == 0)
                sum+=c;
            }
        printf("%ld\n",sum);
        sum=0;
        c=0;
        a=-1;
        b=1;

    }

}
