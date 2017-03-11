#include<bits/stdc++.h>
using namespace std;

int main()
{
    long count=0,n,a[3000],i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
            ++count;
        if(a[i]==a[i-1] && a[i]==a[i+1]-1)
            ++count;
    }
    cout<<count;

}
