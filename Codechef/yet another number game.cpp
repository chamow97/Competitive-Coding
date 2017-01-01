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

        if(n%2 == 0)
        {
            printf("ALICE\n");
        }
        else
        {
            printf("BOB\n");
        }
    }
}
