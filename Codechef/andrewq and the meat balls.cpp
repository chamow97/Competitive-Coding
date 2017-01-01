#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long i,sum=0,count=0,t,n,p[7],m;
    cin>>t;
    while(t--)
    {
        sum=0;
        count=0;
        cin>>n>>m;
        for(i=0;i<n;i++)

            cin>>p[i];
        sort(p, p+n);
        for(i=n-1;i>=0;i--)
        {
            sum+=p[i];
            ++count;
            if(sum>=m)
            {
               break;
            }
        }
        if(sum<m)
            count=-1;

        cout<<count<<'\n';
    }
}
