#include<stdio.h>

using namespace std;

int main()
{

    for(int i=0;i<1;i++)
    {
        int j,k,count=0,a[10];
        for(j=0;j<10;j++)
        {
            scanf("%d",&a[j]);
        }
        for(j=0;j<10;j++)
        {
            a[j]=a[j]%42;
        }

        for(j=0;j<10;j++)
        {
            for(k=0;k<10;k++)
            {
                if(a[k]!=-1 && k!=j)
                {
                    if(a[j]==a[k])
                    {
                        a[k]=-1;
                    }
                }
            }
        }
        for(j=0;j<10;j++)
        {


        printf("%d ",a[j]);
          //  if(a[j]!=-1)
            //   ++count;
        }
        printf("%d\n",count);
    }

}
