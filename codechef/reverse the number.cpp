#include<stdio.h>

using namespace std;
int main()
         {
            long int t,i;
            scanf("%ld",&t);
            for(i=0;i<t;i++)
             {
                 long int n;
                 scanf("%ld",&n);
                 long int temp,rev=0;
                 while(n)
                 {
                     temp = n%10;
                     n/=10;
                     rev = ((rev*10)+temp);
                 }
                 printf("%ld\n",rev);

             }
         }
