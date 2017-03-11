#include<stdio.h>

using namespace std;
int k=0;
long int n;
int min(int a,int b,int c)
{
    if(a<=b && a<=c)
       {
        return a;
        k+=1;

       }
    else if(b<=c && b<=a)
        {return b;
        k+=2;

        }
    else if(c<=a && c<=b)
        {return c;
        k+=3;

        }

}
int main()
{
    long int sum=0;

    scanf("%ld",&n);
    long int temp=n;
    int a[n],i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        while(temp!=0)
        {
            sum+=min(a[k],a[k+1],a[k+2]);
            temp-=3;
            if(temp/3==0)
                break;
        }
        if((n-k)>=3)
        {
            sum+=min(a[k],a[k+1],a[k+2]);
        }
    printf("%ld\n",sum);

}
