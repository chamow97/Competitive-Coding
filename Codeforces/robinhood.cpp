#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long i,j,n,k,minimum,maximum;
    long long pos,pos1;
    cin>>n>>k;
    long long a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<k;i++)
    {
        sort(a,a+n);
        a[0]++;

    }
    for(i=0;i<k;i++)
    {
        sort(a,a+n);
        a[n-1]--;

    }
    cout<<a[n-1]-a[0];


}
