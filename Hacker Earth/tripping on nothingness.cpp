#include<stdio.h>

using namespace std;



int main()
{
    long int s,q,i;
    scanf("%ld %ld",&s,&q);
    long int a[q],b[q];
    for(i=0;i<q;i++)
    {
        long int small,j,element;
        scanf("%ld",&a[i]);
        if(s<a[i])
        {
            small = s;
        }
        else
        {
            small = a[i];
        }
        for(j=1;j<=small;j++)
        {
            if(s%j==0 && a[i]%j==0)
            {
                element = j;
            }
            b[i]=element;

        }
        for(j=0;j<=i-1;j++)
        {
            if(element == b[j])
            {
                element = -1;
            }
        }
        printf("%ld\n",element);


    }

}
