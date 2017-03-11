#include<stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    long long int a[n];
    for(int i=0;i<n;i++)
    {

        scanf("%lld",a[i]);


        if(i>0)
        {

          a[0]+=a[i];
        }
    }


}
