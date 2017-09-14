#include<bits/stdc++.h>

using namespace std;

int main()
{
    long int t,n,a[1000],b[1000],sum=0,i;
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
            cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        for(i=0;i<n;i++)
            sum+=(a[i]*b[i]);

        cout<<sum<<'\n';



    }
}
