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
        int temp,j,sum=0;

        for(j=0;n!=0;++j)
        {
            temp = n%10;
            n/=10;
            if(j==0)
            {
                sum+=temp;
            }
        }
        sum+=temp;
        printf("%d\n",sum);
    }
}
