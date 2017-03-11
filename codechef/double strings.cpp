#include<stdio.h>

using namespace std;

int main()
{
    long int t,i;
    scanf("%ld",&t);
    for(i=0;i<t;i++)
    {
        long int n;
        scanf("%ld",&n);

        if(n%2==0)
            printf("%ld\n",n);
        else if(n%2!=0)
            printf("%ld\n",n-1);
    }

}
