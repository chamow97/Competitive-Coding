#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long t,k,result;

    cin>>t;
    while(t--)
    {
        char a[200];
        a[0]='2';
        a[1]='9';
        a[2]='1';
        cin>>k;
        result=((k-1)*250)+192;
        cout<<result<<'\n';

    }
}
