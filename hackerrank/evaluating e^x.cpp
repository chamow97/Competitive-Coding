#include<stdio.h>
#include<math.h>

using namespace std;
int main()
{
    int n,i,j,k;


    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        float sum=0.0;
        long int fact=1;
        float x;
        scanf("%f",&x);

        for(j=2;j<=9;j++)
        {   fact*=j;
            sum+=((pow(x,j))/fact);

        }

        printf("%f\n",sum+1.0+x);

    }

}
