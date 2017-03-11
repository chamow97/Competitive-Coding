#include<iostream>

using namespace std;

int main()
{
    int sum=0;
    long int n,i,temp=5;
    cin>>n;
    long int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        while((a[i]/temp)>0)
        {
            sum+=a[i]/temp;
            temp*=5;
        }
        cout<<sum<<endl;
        sum=0;
        temp=5;
    }

}
