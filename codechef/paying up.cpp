#include<bits/stdc++.h>
using namespace std;

void subset(long a[20],long n,long m)
{
    long i,j,k=1<<n,flag=0;

    for(i=0;i<k;i++)
    {
        long sum=0;
        for(j=0;j<n;j++)
        {

            if((1<<j)&i)
                sum+=a[j];

        }
        if(sum==m)
        {
            flag=1;
            break;
        }
        else
            flag=0;

    }
    if(flag==1)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}

int main()
{
    long i,n,m,t,a[20];

    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
            cin>>a[i];
        subset(a,n,m);
    }
}
