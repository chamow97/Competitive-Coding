#include<iostream>

using namespace std;
int main()
{
    int n,i,j,n1=0,n2=0;
    cin>>n;
    int a[n][2];

    for(i=0;i<n;i++)
    {
        for(j=0;j<2;j++)
        {
         cin>>a[i][j];
        }
    }

    int diff[n],diff1[n];

    for(i=0;i<n;i++)
    {
        for(j=0;j<1;j++)
        {
            if(a[i][j]>a[i][j+1])
            {
                ++n1;
                diff[i]=(a[i][j]-a[i][j+1]);
                diff1[i]=0;
            }
            else
            {
                ++n1;
                diff1[i]=(a[i][j+1]-a[i][j]);
                diff[i]=0;
            }

        }
    }

    int largest=0,largest1=0;

    largest=diff[0];
    largest1=diff1[0];

    for(i=1;i<n1;i++)
    {

        if(largest<=diff[i])
            largest=diff[i];


    }
    for(i=1;i<n1;i++)
    {
        if(largest1<diff1[i])
            largest1 = diff1[i];
    }

    if(largest>largest1)
        cout<<"1 "<<largest;

    else
        cout<<"2 "<<largest1;



}
