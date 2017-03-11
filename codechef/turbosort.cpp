#include<stdio.h>


using namespace std;

int main()
{


   long int t,i,j;
   int temp;
   scanf("%ld",&t);
   long int a[t];
   for(i=0;i<t;i++)
   {
       scanf("%ld",&a[i]);

   }
   for(i=0;i<t;i++)
   {
       for(j=0;j<t-1-i;j++)
       {
           if(a[j]>a[j+1])
           {
               temp = a[j];
               a[j] = a[j+1];
               a[j+1] = temp;
           }
       }

   }
   for(i=0;i<t;i++)
    printf("%ld\n",a[i]);
}
