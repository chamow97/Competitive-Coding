#include<stdio.h>

using namespace std;

long int pal(long int n)
{
    int temp,sum=0;
    while(n!=0)
    {
        temp=n%10;
        n/=10;
        sum=((sum*10)+temp);

    }
    return sum;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int count=0;
        long int n,n1,sum;
        scanf("%ld",&n);

        n1=pal(n);
        sum=n+n1;
        while(pal(sum)!=sum)
        {
            ++count;
            n1=pal(sum);
            sum+=n1;
        }
        printf("%d %ld\n",count+1,sum);


    }
}
