#include<bits/stdc++.h>
using namespace std;
int main()
{
    long t,n,a[100000],b[100000],i;
    bool isequal=false;
    cin>>t;
    while(t--)
    {
        isequal=false;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        for(i=1;i<n;i++)
        {
            a[i]=a[i]+a[i-1];
        }
        for(i=n-2;i>=0;i--)
        {
            b[i]=b[i]+b[i+1];
        }
        for(i=0;i<n;i++)
        {
            if(b[i]==a[i])
            {
                isequal=true;
                break;
            }
            else
            {
                isequal=false;
            }
        }
        if(isequal==true)
        {
            cout<<"YES\n";

        }
        else
        {
            cout<<"NO\n";

        }

    }
}
