#include<stdio.h>

using namespace std;

int main()
{
    int t,i;

    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);


        int temp,temp2=0;

        temp = n-m;
        if(temp<0)
            temp=(temp*(-1));
        while(temp>0 && k>0)
        {
            --temp;
            --k;
        }
        while(k>0)
        {
            ++temp2;
            --k;

        }

        printf("%d\n",temp+(temp2%2));
    }
}
