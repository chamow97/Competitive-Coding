#include<stdio.h>

using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long int n,i,j;
        int count=0;
        int flag=0;
        scanf("%ld",&n);

        for(i=n;i>0;i--)
        {
            if(n%i==0)
            {
                for(j=2;j<i/2;j++)
                {
                    if(i%j==0)
                    {
                        flag=0;
                        break;
                    }
                    else
                        flag=1;
                }
                if(flag==1)
                {
                    ++count;
                    n=(n-i);
                }
            }
        }
        printf("%d\n",count);
    }
}
