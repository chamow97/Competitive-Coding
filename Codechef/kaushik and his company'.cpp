#include<stdio.h>
using namespace std;


int main()
{
    long int n,q;
    scanf("%ld %ld",&n,&q);
    int a[n];
    long int i,j;
    for(i=0;i<n;i++)
        a[i]=1;

        for(j=0;j<q;j++)
        {
            char s[100];
            scanf("%s",&s);
            long int k;
            int flag=0;
            switch(s[0])
            {
            case 'C':
            case 'c':
                long int x;
                scanf("%ld",&x);
                if(a[x]==1)
                a[x]=0;
                else
                    a[x]=1;
                break;
            case 'I':
                case 'i':
                long int x1;
                scanf("%ld",&x1);
                for(k=x1;k<n;k++)
                {
                    if(a[k]==0)
                    {
                        flag=1;
                        break;
                    }
                    else
                        flag=0;
                }
                if(flag==1)
                    printf("%ld\n",k);
                else if(flag==0)
                    printf("-1\n");
            }
        }

}
