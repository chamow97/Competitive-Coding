#include<stdio.h>

using namespace std;
int main()
{
    long int t,n,i,j;

    scanf("%ld",&t);
    for(i=0;i<t;i++)
    {
        long int s=0,p=0;
        scanf("%ld",&n);

        for(j=1;j<=n;j++)
        {
            s+=(j*j);
            p+=j;
        }
        printf("%ld\n",(p*p)-s);
    }
}
