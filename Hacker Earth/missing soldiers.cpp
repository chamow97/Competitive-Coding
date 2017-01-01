#include<stdio.h>

using namespace std;

int main()
{
    long int i,n,count=0;
    scanf("%ld",&n);

    for(i=0;i<n;i++)
    {
        long int x,y,d,j;
        scanf("%ld %ld %ld",&x,&y,&d);

        for(j=x;j<=(x+d);j++)
            ++count;
    }
    printf("%ld",count);
}
