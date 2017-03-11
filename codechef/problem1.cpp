#include<stdio.h>

using namespace std;

long int reverse(long int a)
{
    long int t,rev=0,count=1;
    while(a!=0)
    {
        t=a%10;
        if(t==0)
            count*=(-1);
        else count*=0;
        a/=10;
        if(count==0)
        rev=((rev*10)+t);
    }
    return rev;

}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        long int a,b,temp1,temp2,rev1,rev2;
        scanf("%ld %ld",&a,&b);
        temp1=a;
        temp2=b;

        rev1=reverse(temp1);
        rev2=reverse(temp2);

        long int temp3,rev3;
        temp3=rev1+rev2;

        rev3=reverse(temp3);
        printf("%ld\n",rev3);
    }
}
