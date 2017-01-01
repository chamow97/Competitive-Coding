#include<bits/stdc++.h>
using namespace std;
int main()
{
    int maximum,sum,t,n,temp,i;
    long long g;
    cin>>t;
    while(t--)
    {
        sum=0;
        maximum=0;
        cin>>n>>g;
        for(i=0;i<n;i++)
        {
            cin>>temp;
            maximum=max(maximum,temp);
            sum+=(temp);
        }
        if(sum<=(g*2)&&maximum<=g)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }


    }
}
