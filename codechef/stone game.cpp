#include<stdio.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,p=-1;
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        for(i=0;i<n;i++)
        {
            while((a[i]-(i+1))>=0)
            {
                a[i]-=(i+1);
                p*=(-1);
            }
        }
        if(p==1)
            printf("ALICE\n");
        else if(p==-1)
            printf("BOB\n");

    }
}
