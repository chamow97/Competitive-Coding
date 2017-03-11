#include<stdio.h>

using namespace std;

int main()
{

   int i,k,j,lines,a[100][100];

   scanf("%d",&lines);

   for(i=0;i<lines;i++)
   {
       for(j=0;j<=i;j++)
       {
           if(j==0 || j==i)
           {
               a[i][j] = 1;
           }
           else
           {
               a[i][j] = a[i-1][j-1]+a[i-1][j];
           }
       }
   }

   for(i=0;i<lines;i++)
   {
       for(k=0;k<lines-1-i;k++)
       {
           printf(" ");
       }
       for(j=0;j<=i;j++)
       {
           printf("%d ",a[i][j]);
       }

       printf("\n");
   }
}
