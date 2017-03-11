#include<bits/stdc++.h>

using namespace std;

int main()
{
    long t,a[100000],n,i,count=0;
    cin>>t;
    while(t--)
    {
        count=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {


            if(i>0)
            {

            if(a[i]!=a[i-1] )
            {

                count++;
                continue;

            }
            }

            if(i<n-1)
            {

            if(a[i]!=a[i+1])
            {
                count++;
            }
            }



        }
        cout<<count<<'\n';
    }
}
