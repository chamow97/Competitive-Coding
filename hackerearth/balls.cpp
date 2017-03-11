#include<stdio.h>

using namespace std;

int main()
{
    long int n,i,sum=0;
    scanf("%ld",&n);

    long int a[n];


    for(i=0;i<n;i++)
    {
        scanf("%ld",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]<((i+1)*(i+1)))
        {
            sum+=(((i+1)*(i+1)-a[i]));
        }
    }
    printf("%ld",sum);

}
