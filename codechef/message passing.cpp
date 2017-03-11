#include<stdio.h>

using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    long int i;
    while(t--)
    {
        long int n,result=0;
        scanf("%ld",&n);
        long int a,b;

        for(i=0;i<n;i++)
            {

            scanf("%ld%ld",&a,&b);
            result+=b;

            }

        printf("%ld\n",((n)*(n+1))/2-result);

    }
}
