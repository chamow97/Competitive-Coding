#include<stdio.h>

using namespace std;

int main()
{
    int t,i;
    scanf("%d",&t);
    long int arr[t];
   for(i=0;i<t;i++)
   {


        long int a,b,c,ring1=0,small,result1=0,result2=0,t1,t2,t3;
        scanf("%ld %ld %ld",&a,&b,&c);
        t1=a;
        t2=b;
        t3=c;
        ring1=((a/3)+(b/3)+(c/3));
        a=(a%3);
        b=(b%3);
        c=(c%3);
        small=(a<b)?((a<c)?a:c):((b<c)?b:c);
        result1=(ring1+small);

       small=(t1<t2)?((t1<t3)?t1:t3):((t2<t3)?t2:t3);
        t1=(t1-small);
        t2=(t2-small);
        t3=(t3-small);
        ring1=((t1/3)+(t2/3)+(t3/3));

        result2=(ring1+small);

        if(result1>=result2)
            printf("%ld\n",result1);
        else
            printf("%ld\n",result2);
   }


}
