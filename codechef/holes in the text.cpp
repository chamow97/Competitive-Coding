#include<stdio.h>

using namespace std;

int main()
{

    long int t,i;
    scanf("%ld",&t);

    for(i=0;i<t;i++)
    {
        char string[105];
        long int j=0,sum=0;



        scanf("%s",string);

        while(string[j]!='\0')
        {
            switch(string[j])
            {
            case 'A':
            case 'D':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
                ++sum;
                break;

            case 'B':
                sum+=2;
                break;
            default :
                sum+=0;
            }
            ++j;
        }
        printf("%ld\n",sum);

    }

}
