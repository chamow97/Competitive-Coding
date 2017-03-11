#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);


    while(t--)
    {
        long int n,r=0,g=0,b=0,i,max=0;
        scanf("%ld",&n);
        char a[n];
        scanf("%s",&a);
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]=='R')
                ++r;
            else if(a[i]=='B')
                ++b;
            else
                ++g;
        }

        if(r>=g && r>=b)
            max=r;
        else if(g>=b && g>=r)
            max=g;
        else
            max=b;

        printf("%ld\n",n-max);

    }
}
