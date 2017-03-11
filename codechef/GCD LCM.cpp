#include<stdio.h>

using namespace std;

int main()
{
int i,t;
scanf("%d",&t);
for(i=0;i<t;i++)
{
    long int a,b,j,lcm;
    long int sm,lar;
    int gcd;
    scanf("%ld %ld",&a,&b);
    sm = (a>b) ? b : a;
    lar = (a>b) ? a : b;
    for(j=1;j<=sm;j++)
    {
        if((lar % j ==0) && (sm % j ==0) )
        {
            gcd = j;
        }
    }
   lcm = (a*b)/gcd;

    printf("%d %ld\n",gcd,lcm);
}

}
