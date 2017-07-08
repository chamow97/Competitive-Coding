#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long b,d,s,temp,maximum,e,f,g,ans=0;
    cin>>b>>d>>s;
    if(b==d && d==s)
        cout<<"0";
    else if(b==s && d==1 && b==0)
    {
        cout<<"0";
    }
    else if(b==d && s==1 && b==0)
    {
        cout<<"0";
    }
    else if(s==d && b==1 && s==0)
    {
        cout<<"0";
    }
    else
    {
        e=b;
        f=d;
        g=s;
        maximum=0;
        maximum=max(maximum,e);
        maximum=max(maximum,f);
        maximum=max(maximum,g);
        maximum=maximum-1;
        temp=maximum-e;
        if(temp>0)
            ans+=temp;
        temp=maximum-f;
        if(temp>0)
            ans+=temp;
            temp=maximum-g;
        if(temp>0)
            ans+=temp;
        cout<<ans;
    }
}
