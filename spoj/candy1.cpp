#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n,a[10000],i;
    long long sum=0,moves;
    while(1)
    {
        sum=0;
        moves=0;
        cin>>n;
        if(n==-1)
            break;
        else
        {

            for(i=0;i<n;i++)
            {
                cin>>a[i];
                sum+=a[i];
            }
            if(n==1)
            {
                cout<<"0\n";
                continue;
            }
            if(sum%n==0)
                {
                    for(i=0;i<n;i++)
                    {
                        moves+=((max(sum/n,a[i]))-(min(sum/n,a[i])));

                    }
                    cout<<moves/2<<'\n';
                }
            else
                cout<<"-1\n";
        }
    }
}
