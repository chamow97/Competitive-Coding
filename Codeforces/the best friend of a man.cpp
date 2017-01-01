#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long tot=0,i,n,k,a[500];
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<n;i++)
    {
        if((a[i]+a[i-1])<k)
        {
            tot+=(k-(a[i]+a[i-1]));
            a[i]=k-a[i-1];
        }
    }
    cout<<tot<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
}
