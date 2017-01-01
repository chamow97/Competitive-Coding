#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long k,r,i,ans;
    bool found=false;
    cin>>k>>r;
    for(i=1;i<=9;i++)
    {
        if((k*i)%10==r)
        {
            found=true;
            ans=k;
            break;
        }
    }
    if(found==false)
    {
        for(i=1;i<=9;i++)
        {
            if((k*i)%10==0)
                {ans=k;
                break;
                }
        }
    }
    cout<<ans;
}
