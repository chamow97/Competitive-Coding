#include<stdio.h>

using namespace std;

int main()
{

   int small,pos,i,size,a[100],j,temp;
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<size;i++)
    {
        small = a[i];
        pos = i;
        for(j=i+1;j<size;j++)
        {
            if(small > a[j])
            {
                small = a[j];
                pos = j;
            }
        }
        temp = a[pos];
        a[pos] = a[i];
        a[i] = temp;

    }
    for(i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
}
