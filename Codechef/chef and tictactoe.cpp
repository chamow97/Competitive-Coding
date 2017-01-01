#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int t,n,k;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&k);
        int loop1=0,i,j,flag,flag1,loop2;
        char a[n][n];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]=='.')
                    a[i][j]='X';
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<k;j++)
            {
                if(a[i][j]=='X')
                    flag=1;
                if(a[i][j]!='X')
                {
                    flag=0;
                    loop1++;
                }
                if(a[j][i]=='X')
                    flag1=1;
                if(a[j][i]!='X')
                {flag1=0;
                loop2++;
                }
                //if(a[n-1-i][n-1-j]=='X')


            }
        }
        if((flag1==1 && loop2==0)||(flag==1 && loop1==0))
        {
            printf("YES");
        }

    }
}
