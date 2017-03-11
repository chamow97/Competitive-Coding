#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long i,counter=0,l=0,n,k,a[100];
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    while(counter<k)
    {
        counter+=a[l];
        if(counter>k)
            break;
        cout<<l+1<<' ';
        ++l;
    }
}
