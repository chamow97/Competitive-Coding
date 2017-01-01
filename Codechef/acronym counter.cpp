#include<stdio.h>

using namespace std;

int main()
{
    char s[1001],b[1001];
    gets(s);
    int i,count=0,j=0,k;

    while(1)
    {
        if(s[i]=='\0')
                break;

        while(1)
        {
            if(s[i]==' ')
                break;

            b[j++]=s[i];
            ++i;
        }

            //if(b[0]>=65 && b[0]<=90 && b[1]>=65 && b[1]<=90)
               // ++count;




        //b[0]='\0';
        //j=0;

    }
    printf("%d\n",count);

}
