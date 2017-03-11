#include<stdio.h>

using namespace std;

int main()
{
    long int t,i;

    scanf("%ld",&t);

    for(i=0;i<t;i++)
    {
        long int n,t,temp,pal=0;

        scanf("%ld",&n);
        t=n;
        while(n)
        {
            temp = n%10;
            n/= 10;
            pal=((pal*10)+temp);
        }
        if(pal == t)
        {
            printf("wins\n");
        }
        else
        {
            printf("losses\n");
        }
    }
}
