#include<stdio.h>

using namespace std;

int main()
{
    long int n,i,c,c1,c2;
    int l=1,m=2,o=3;
    scanf("%ld",&n);
    long int a[n];
    for(i=0;i<n;i++)
        scanf("%ld",&a[i]);

    for(i=0;i<n;i++)
    {
        if(i==l)
        {
         ++c;
         l+=3;
        }
        else if(i==m)
        {
            ++c1;
            m+=3;
        }
        else if(i==o)
        {
            ++c2;
            o+=3;
        }

    }
    printf("%ld %ld %ld",c,c1,c2);

}
