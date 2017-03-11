#include<iostream>

using namespace std;

int main()
{
    long int sum3=0,sum1=0,sum2=0,i,n,a[100000];

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]%2==0)
            ++sum1;
        else
            ++sum2;
    }
    sum3=(sum1-sum2);
    if(sum3<0)
    {
        sum3=((sum3)*(-1));
    }
    cout<<sum3<<'\n';

}
