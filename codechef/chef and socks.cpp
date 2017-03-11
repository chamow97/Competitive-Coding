#include<stdio.h>

using namespace std;

int main()
{
    long int j,s,m,count=0;

    scanf("%ld %ld %ld",&j,&s,&m);

    m-=j;

    while(1)
    {
        m-=s;
        ++count;
        if((m-s)<0)
            break;
    }

    if(count%2!=0)
    {
        printf("Unlucky Chef");

    }
    else
        printf("Lucky Chef");

}
