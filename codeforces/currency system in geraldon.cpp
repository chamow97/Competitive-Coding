#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n,a[1001],i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    if(a[0]==1)
        cout<<"-1\n";
    else
        cout<<"1\n";
}
