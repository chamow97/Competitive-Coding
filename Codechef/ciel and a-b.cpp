#include<stdio.h>

using namespace std;
int main()
{
    long int a,b,result,temp;
    scanf("%ld %ld",&a,&b);
    result = a-b;
    temp = result%10;
    if(temp == 0)
    {
        result+=1;
    }
    else if(temp == 9)
    {
        result-=1;
    }
    else
    {
        result+=1;
    }
    printf("%ld\n",result);
}
