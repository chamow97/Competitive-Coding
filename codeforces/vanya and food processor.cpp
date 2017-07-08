#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n,h,k,a[10000],flag=1,sum=0;
    cin>>n>>h>>k;
    for(i=0;i<n;i++)
    {
    cin>>a[i];
    sum+=a[i];
    sum=sum%a[i];

        if(i>0 && a[i]==a[i-1] && flag==1)
        flag=1;
        else if(i>0)
        flag=0;
    }
    if(flag==1)
    {
        if(a[0]>k)
            cout<<n*2;
        else
            cout<<n;
    }
    else
    {

    }
}

