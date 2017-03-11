#include<stdio.h>

using namespace std;
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        int count=0;
        scanf("%d",&n);

        while(n>0)
        {
            n-=2;
            count+=(n/2);
        }
        printf("%d\n",count);
    }
}
