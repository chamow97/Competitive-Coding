#include<stdio.h>
#include<math.h>

using namespace std;
int main()
{
    int t,i;
    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        long int n,x,m,j,t,k;
        scanf("%ld %ld %ld",&n,&x,&m);

        long int *a = new long int;

        for(j=0;j<n;j++)
        {
            scanf("%ld",&a[j]);
        }
        for(j=0;j<m;j++)
        {
            for(k=1;k<m;k++)
            {
               a[k]=(a[k]+a[k-1]);
            }
        }
        long int val=((pow(10,9))+7);
        printf("%ld\n",(a[x-1]%val));
        delete[] a;
    }

}
