#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long t,stamp,sum,i,loop,n,a[1000];
    cin>>t;
    for(loop=0;loop<t;loop++)
    {
        sum=0;
        cin>>stamp>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n,greater<int>());
        for(i=0;i<n;i++)
        {
            sum+=a[i];
            if(sum>=stamp)
                break;
        }
        if(sum>=stamp)
        cout<<"Scenario #"<<loop+1<<":\n"<<i+1<<"\n\n";

        else
            cout<<"Scenario #"<<loop+1<<":\n"<<"impossible"<<"\n\n";
    }
}
