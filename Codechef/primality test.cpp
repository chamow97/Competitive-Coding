#include<stdio.h>

using namespace std;
int main()
{
    long int i,t;
    scanf("%ld",&t);

    for(i=0;i<t;i++)
    {
        long int n,j,flag=0;
        scanf("%ld",&n);
        for(j=2;j<=n/2;j++)
        {
            if(n%j ==0)
            {
                flag=0;
                break;
            }
            else
                flag=1;
        }
        if(flag == 1|| (n==2 || n==3))
        {
            printf("yes\n");
            flag=0;

        }
        else if(flag==0 )
        {
            printf("no\n");
        }
    }
}
