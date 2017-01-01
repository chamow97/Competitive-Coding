#include<stdio.h>

using namespace std;

int main()
{
    int t;
    long int n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld",&n);
        long int a[n],sum=0,moves=0,num,ans=0;
        int flag=0;
        for(i=0;i<n;i++)
        {
            scanf("%ld",&a[i]);
            sum+=a[i];
        }
        for(i=0;i<n;i++)
        {
            if(sum%n==0)
            {
                num=sum/n;
                flag=1;
                break;
            }
            else flag=0;
        }
        if(flag==1)
        {


        for(i=0;i<n;i++)
        {
            if(a[i]>=num)
                moves+=a[i]-num;
            else if(a[i]<num)
                moves+=num-a[i];
        }
        ans=moves/2;

        printf("%ld\n",ans);
        }
        else
        {
            printf("No Treat\n");
        }


    }



}
