#include<stdio.h>

using namespace std;

int main()
{

    int t,i,j,k;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int a[30],b[30],n,sum=0,temp;
        scanf("%d",&n);

        for(j=0;j<n;j++)
            scanf("%d",&a[j]);

        for(j=0;j<n;j++)
            scanf("%d",&b[j]);
            for(k=0;k<n;k++)
            {


            for(j=0;j<n-1-k;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
            }
            for(k=0;k<n;k++)
            {


            for(j=0;j<n-1-k;j++)
            {
                if(b[j]>b[j+1])
                {
                    temp=b[j];
                    b[j]=b[j+1];
                    b[j+1]=temp;
                }
            }
            }




            k=0;

            for(j=0;j<n;j++)
            {

               if(b[j]/a[k]>0)
                {
                    ++sum;
                    a[k]=0;
                    b[j]=0;
                    ++k;

                }
                else if(b[j]/a[k]==0)
                {
                    b[j]=0;
                }

            }

            printf("%d\n",sum);
    }


}
