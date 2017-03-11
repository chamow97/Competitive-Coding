#include<stdio.h>


using namespace std;

int main()
{
    int t,i;
    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        int n;
        long int j,k,temp,small=0;
        scanf("%d",&n);
        long int a[n];

        for(j=0;j<n;j++)
            scanf("%ld",&a[j]);
        small = a[0] - a[n-1];
        if(small<0)
            small = (small*(-1));
        for(j=0;j<n-1;j++)
        {
            for(k=j+1;k<n;k++)
            {
                temp = a[j] - a[k];

                if(temp<0)
                    temp = (temp*(-1));

                if(small>temp)
                    small=temp;
            }
        }

        printf("%d\n",small);
    }
}
