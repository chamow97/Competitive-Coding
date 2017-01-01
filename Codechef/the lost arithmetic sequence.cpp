#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n,a[100000],i,minimum,b[100000],counter=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        if(n==2)
        {
            cout<<min(a[0],a[1])<<endl;
        }
        else
        {
            for(i=1;i<n;i++)
            {
                b[i]=a[i]-a[i-1];
                if(b[i]!=b[i-1] && i>1)
                {
                    ++counter;
                }
            }
            if(b[1]==b[n-1])
            {
                cout<<a[0]<<"\n";
            }
            else if(counter>2)
            {
                cout<<"-1\n";
            }
            else
            {

            }
        }
    }
}
