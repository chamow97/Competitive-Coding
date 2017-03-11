#include<stdio.h>

using namespace std;

int main()
{
    long int t,i;
    scanf("%ld",&t);
    for(i=0;i<t;i++)
    {
        long int n,j=0;
        int flag=0;
        scanf("%ld",&n);
        char string[1001];

        scanf("%s",string);

        while(string[j]!='\0')
        {
            if(string[j]=='I')
            {
                flag=1;
                break;
            }
            else if(string[j]=='N')
            {
                flag=2;
            }
            else flag=0;
            ++j;
        }
        if(flag==0)
            printf("NOT INDIAN\n");
        else if(flag==1)
            printf("INDIAN\n");
        else if(flag == 2)
            printf("NOT SURE\n");
    }
}
