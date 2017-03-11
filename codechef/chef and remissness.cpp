#include<stdio.h>

using namespace std;

int main()
{
    int t,i;
    scanf("%d",&t);

    for(i=0;i<t;i++)
    {

        long int a,b;

        scanf("%ld %ld",&a,&b);

        long int count1,count2;

        if(a>b)
        {

            count1=a;
            count2=a+b;
        }
        else if(b>=a)
          {

           count2=b;
            count1=a+b;
          }
          if(count1<=count2)
        printf("%ld %ld\n",count1,count2);

        else
         printf("%ld %ld\n",count2,count1);

    }


}
