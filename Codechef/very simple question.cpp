#include<stdio.h>

using namespace std;

int main()
{
    long long int n,q,i,j;
    scanf("%lli",&n);
    long long int arr[n];

    for(i=0;i<n;i++)
        scanf("%lli",&arr[i]);

    scanf("%lli",&q);
    for(i=0;i<q;i++)
    {
        long long int a,b,count=0;
        scanf("%lli %lli",&a,&b);

        for(j=0;j<n;j++)
        {
            if(a<=arr[j] && b>=arr[j])
                ++count;
        }
        printf("%lli\n",count);

    }

}
