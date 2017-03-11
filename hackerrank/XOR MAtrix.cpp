#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long temp,j,n,m,a[100000],b[100000],i;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    if((n&(n-1))==0)
    {
        if(m>n)
        {
            for(i=0;i<n;i++)
            {
                cout<<"0 ";
            }
        }
        else
        {
            for(j=2;j<=m;j++)
        {
        temp=a[0];
        for(i=0;i<n-1;i++)
        {
        b[i]=a[i]^a[i+1];
        a[i]=b[i];
        }
        b[n-1]=a[n-1]^temp;
        a[n-1]=b[n-1];
    }
    for(i=0;i<n;i++)
        cout<<b[i]<<' ';

        }
    }
    else
    {
        temp=pow(2,(n/2)+1);
        temp=temp-1;
        
        if(m==1)
        {
            for(i=0;i<n;i++)
        cout<<b[i]<<' ';

        }
        else
        {
            m=m%temp;
            m=m+2;
            for(j=2;j<=temp;j++)
        {
        temp=a[0];
        for(i=0;i<n-1;i++)
        {
        b[i]=a[i]^a[i+1];
        a[i]=b[i];
        }
        b[n-1]=a[n-1]^temp;
        a[n-1]=b[n-1];
    }
    for(i=0;i<n;i++)
        cout<<b[i]<<' ';

        }
    }
    }



    

   

