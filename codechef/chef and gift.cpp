#include<iostream>

using namespace std;

int main()
{
    int t,n,k,a[50],i,count=0;

    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=0;i<n;i++)
            cin>>a[i];

         count=0;

        for(i=0;i<n;i++)
        {
            if(a[i]%2==0)
            {
                count+=1;

            }

        }
        if(k==0 && count==n)
           {
            cout<<"NO\n";
           }
        else if(count>=k)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

}
