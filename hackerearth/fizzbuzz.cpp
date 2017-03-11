#include<stdio.h>

using namespace std;

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        long int n,j;
        scanf("%ld",&n);

        for(j=1;j<=n;j++)
        {
            if(j%3 == 0 && j%5 == 0)
            {
                printf("FizzBuzz\n");
            }
            else if(j%3 == 0)
            {
                printf("Fizz\n");
            }
            else if(j%5 == 0)
            {
                printf("Buzz\n");
            }
            else
            {
                printf("%ld\n",j);
            }
        }
    }
}
