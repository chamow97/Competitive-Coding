#include<iostream>

using namespace std;

int main()
{
    long int sum=0,t,n,x,rem,flag=0,i;
    cin>>t;
    while(t--)
    {
        flag=0;
        sum=0;
        cin>>n>>x;
        long int a[n];
        for(i=0;i<n;i++)
        {

            cin>>a[i];
            sum+=a[i];
        }
        rem=sum%x;

        for(i=0;i<n;i++)
        {
            if(a[i]<=rem)
            {

                flag=1;
                break;
            }
        }
        if(flag==1)
            cout<<"-1\n";
        else
            cout<<sum/x<<"\n";


    }
}

