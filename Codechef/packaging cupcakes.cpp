#include<stdio.h>

using namespace std;
 int main()
 {
     int t,i;
     long int j;
     scanf("%d",&t);

     for(i=0;i<t;i++)
     {
         long int n;
         scanf("%ld",&n);
         int max=0;
         for(j=1;j<=(n+1)/2;j++)
         {
             if((n%j)>=max)
                max=n%j;
         }

         printf("%d\n",n-max);
     }
 }
