#include<stdio.h>
using namespace std;

int main()
{
    long int i,sum=0,t,a,b,c,k,rem=0,temp=0;
    scanf("%ld",&t);
    while(t--)
    {
        sum=0;
        temp=0;
        scanf("%ld%ld%ld%ld",&a,&b,&c,&k);
        sum+=c;
        temp=(a*2)+(b);
        rem=a+b;
        i=0;
            while(sum<k)
            {
                sum+=rem;
                i++;
                rem+=(temp);
            }
            if(i==1 && k<c)
            printf("-1\n");


            else
            printf("%ld\n",i);

    }

}
