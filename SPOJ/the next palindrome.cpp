#include<stdio.h>

using namespace std;

int main()
{
    long int t,i;
    scanf("%ld",&t);
    for(i=0;i<t;i++)
    {
        long int n,j;
        scanf("%ld",&n);

        for(j=n+1;;j++)
        {
            long int backup = j;
            int temp;
            long int pal=0;
            while(backup!=0)
            {
                temp = backup%10;
                backup/=10;
                pal=((pal*10)+temp);
            }
            if(pal == j)
            {
                printf("%ld\n",j);
                break;
            }
        }
    }
}
