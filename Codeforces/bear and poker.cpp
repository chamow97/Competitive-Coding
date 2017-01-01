#include<bits/stdc++.h>
using namespace std;
long long hcf(long long a,long long b)
{
    if(b==0)
    {
        return a;
    }
    else
        return hcf(b,a%b);
}
int main()
{
    long long n,a[100000],i,ans=0,two=1,three=1;
    bool found=true;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ans=hcf(a[0],a[1]);
    for(i=2;i<n;i++)
    {
        ans=hcf(ans,a[i]);
    }
    while(ans%2==0)
    {
        ans/=2;
    }
    while(ans%3==0)
    {
        ans/=3;
    }
    for(i=0;i<n;i++)
    {
        two=1;
        three=1;
        while(a[i]%(two*2)==0)
        {
            two*=2;
        }
        while(a[i]%(three*3)==0)
        {
            three*=3;
        }
        if(ans*three*two!=a[i])
        {
            found=false;
            break;
        }

    }
    if(found==false)
    {
        cout<<"No";
    }
    else
    {
        cout<<"Yes";
    }


}
