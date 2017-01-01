#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,a[101],b[101],counter=0;
    cin>>n;
    for(i=1;i<=100;i++)
    {
        b[i]=0;
    }
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]=b[a[i]]+1;
    }
    for(i=1;i<=100;i++)
    {
        counter+=(b[i]/2);
    }
    cout<<counter;
    return 0;
}
