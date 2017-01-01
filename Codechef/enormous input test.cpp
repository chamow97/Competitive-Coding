#include<iostream>

using namespace std;

int main()
{
    long int n,k,sum=0,i;
    cin>>n>>k;
    long int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        if(a[i] % k == 0 )
            ++sum;
    }
    cout<<sum;
}
