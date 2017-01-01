#include<stdio.h>

using namespace std;
int main()
{
  int t,i;
  int a[6];
  a[0]=1;
  a[1]=2;
  a[2]=5;
  a[3]=10;
  a[4]=50;
  a[5]=100;

  scanf("%d",&t);
  for(i=0;i<t;i++)
  {
      long int n;
        int k=5,sum=0;
      scanf("%ld",&n);

      while(n!=0)
      {
          if(n/a[k]!=0)
          {
              sum=((sum)+(n/a[k]));
              n=(n%a[k]);

          }
          else
          {
              --k;
          }
      }

      printf("%d\n",sum);
  }
}
