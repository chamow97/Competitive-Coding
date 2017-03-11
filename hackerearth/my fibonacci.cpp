#include<stdio.h>

using namespace std;

int main()
{
    int a,b,n,j;
    long int c;
    scanf("%d %d %d",&a,&b,&n);
    if(n==2)
        printf("%d",b);

    else if(n==1)
        printf("%d",a);


    else
{


    for(j=0;j<n-2;j++)
    {
        c=a+b;
        a=b;
        b=c;

    }

    printf("%ld",c);
}
}
