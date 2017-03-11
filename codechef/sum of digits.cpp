#include<stdio.h>

using namespace std;

int main()
{
    long int i,t;
    scanf("%ld",&t);
    for(i=0;i<t;i++)
    {
        long int n;

        scanf("%ld",&n);
        long int temp,sumofd=0;
        while(n)
        {
            temp = n%10;
            n/= 10;
            sumofd+=temp;
        }
        printf("%ld\n",sumofd);
    }
}
