#include<iostream>

using namespace std;

int main()
{
    int arr[5]={4,8,2,6,0};
    long int t,a,b,k=0,sum=0,i;
    cin>>t;
    while(t--)
    {
        sum=0;
        k=0;
        cin>>a>>b;
        k=(a%10)/2;
        k-=1;
        for(i=a;i<=b;i++)
        {
            if(i%2==0)
                sum+=(i%10);

            else
            {
                sum+=arr[k];
                k++;
            }
            if(k==4)
                k=0;


        }
        cout<<sum<<"\n";


    }
}
