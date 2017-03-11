#include<stdio.h>

using namespace std;

int main()
{
    int r1,c1,i,j;
    float a[4][4];
    float det=0.0,b[4][4],c[4][4];
    scanf("%d %d",&r1,&c1);
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%f",&a[i][j]);
        }
    }

    for(j=0;j<3;j++)
    {
         det+=(a[0][j]*((a[1][(j+1)%3]*a[2][(j+2)%3])-(a[2][(j+1)%3]*a[1][(j+2)%3])));
    }
        for(i=0;i<r1;i++)
        {


        for(j=0;j<c1;j++)
        {
            b[i][j]=((a[(i+1)%3][(j+1)%3]*a[(i+2)%3][(j+2)%3])-(a[(i+1)%3][(j+2)%3]*a[(i+2)%3][(j+1)%3]));
        }
        }
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                c[j][i]=b[i][j];
            }
        }

        printf("%f",det);
            for(i=0;i<r1;i++)
            {
                for(j=0;j<c1;j++)
                {
                    printf("%4f ",c[i][j]/det);
                }
                printf("\n");
            }




}
