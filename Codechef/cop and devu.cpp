#include<stdio.h>

using namespace std;

int main()
{
    long int t,i;

    scanf("%ld",&t);

    for(i=0;i<t;i++)
    {
        int m=0,x=0,y=0,j=0,k=0,temp=0,sum=0,l,n,o;
        scanf("%d %d %d",&m,&x,&y);
            int a[10];
        for( j=0;j<m;j++)
        {
            scanf("%d",&a[j]);
        }

        for(j=0;j<m;j++)
        {
            for(k=0;k<m-1-j;k++)
            {
                if(a[k]>a[k+1])
                {
                    temp = a[k];
                    a[k] = a[k+1];
                    a[k+1] = temp;
                }
            }
        }


       for(l=0;l<m-1;l++)
        {
            for(n = (a[l]+(x*y))+1 ; n<(a[l+1]-(x*y));n++)
            {
                ++sum;
            }
        }
        for(o=1;o<(a[0]-(x*y));o++)
        {
            ++sum;
        }
        for(int p=100;p>(a[m-1]+(x*y));p--)
        {
            ++sum;
        }

        printf("%d\n",sum);



    }
}
