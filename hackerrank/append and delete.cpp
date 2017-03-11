
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[101],t[101];
    int i,k,n=0,len1=0,len2=0;
    cin>>s;
    cin>>t;
    cin>>k;
    len1=strlen(s);
    len2=strlen(t);
    for(i=0;i<min(len1,len2);i++)
    {
        if(s[i]!=t[i])
        {
            break;
        }
    }

    if(len1==len2 && i==(min(len1,len2)-1))
    {
        n=0;
    }
    else if(len1>=len2)
    {
        n+=(len2-i);
        n+=(len1-i);
    }
    else
    {
        n+=(len2-i);
        n+=(len1-i);
    }
    if((k-n)>=2*len2)
        cout<<"Yes";
    else if((k-n)%2==0 && k>=n)
            cout<<"Yes";
    else if(n==k)
        cout<<"Yes";
    else if((len2+len1)<=k)
        cout<<"Yes";
    else
    {
        cout<<"No";
    }
}
