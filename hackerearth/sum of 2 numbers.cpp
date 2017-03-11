#include<stdio.h>

using namespace std;

int main()
{
    long int t,i;
    scanf("%ld",&t);


    for(i=0;i<t;i++)
    {
        long int a,b;

        scanf("%ld %ld",&a,&b);

        printf("%ld\n",a+b);
    }
}
