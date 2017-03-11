#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n,sum=0,i;
    cin>>n;
    long long a[n],b[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i++)
        cin>>b[i];
    sort(b,b+n);
    for(i=n-1;i>=0;i--)
    {
        sum+=(a[i]*b[i]);
    }
    cout<<sum;
}
