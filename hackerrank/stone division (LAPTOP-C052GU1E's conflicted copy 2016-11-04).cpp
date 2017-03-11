#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long sum=0,n,m,i,s[11],j,k;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>s[i];
    }
    sort(s,s+m);
    for(i=0;i<m;i++)
    {
        for(j=i+1;j<m;j++)
        {
                if(n==s[i]*s[j])
                {
                    sum=(n/s[i])+s[i];
                    break;
                }
        }
    }
    if(sum%2!=0 && sum!=0)
    cout<<"First";
    else
    cout<<"Second";
}
