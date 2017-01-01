#include<stdio.h>
#include<string.h>

int main()
{
    char str[100000];

    gets(str);
    long int i,len=strlen(str);
    long int a[len],b[len],j,count=0;
    a[0]=0;
    b[0]=0;
    for(i=0;i<len;i++)
    {
        switch(str[i])
        {

            case 'L':
                a[i+1]=a[i];
                b[i+1]=b[i]-1;
                break;

            case 'R':
                a[i+1]=a[i];
                b[i+1]=b[i]+1;
                break;
            case 'U':
                a[i+1]=a[i]-1;
                b[i+1]=b[i];
                break;
            case 'D':
                a[i+1]=a[i]+1;
                b[i+1]=b[i];
                break;

        }

    }
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            if(i!=j)
            {
                if(a[i]==a[j] && b[i]==b[j] && a[i]!=-999999)
                {
                    ++count;
                    a[j]=-999999;
                    b[j]=-999999;
                }
            }
        }
    }
    printf("%ld",count+1);


}
