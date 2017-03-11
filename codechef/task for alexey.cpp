#include<bits/stdc++.h>
using namespace std;
long long hcf(long long a,long long b)
{
    if(b!=0)
    {
        return hcf(b,a%b);
    }
    else
    {
        return a;
    }
}
int main()
{
    int t;
    long long n,a[1000],i,j,minimum=9000000000000000000,ans;
    cin>>t;
    while(t--)
    {
        ans=0;
        minimum=9000000000000000000;
        //minimum=1000000000000000000;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }

       sort(a,a+n);

            for(i=0;i<n;i++)
            {
                for(j=i+1;j<n;j++)
            {
                if(a[j]%a[i]==0 && i!=j)
                {
                    minimum=min(minimum,a[j]);
                }
                else if(i!=j)
                {
                    ans=(a[i]*a[j])/hcf(a[i],a[j]);
                    minimum=min(minimum,ans);
                }
            }

            }

        cout<<minimum<<endl;
    }
}
