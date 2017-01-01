#include<bits/stdc++.h>

using namespace std;

int main()
{
    char str[101][101],str1[101][101];
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>str[i]>>str1[i];
    }
    for(i=0;i<n;i++)
    {
        if(str1[i][0]=='r')
            cout<<str[i]<<"\n";
    }
    for(i=0;i<n;i++)
    {
        if(str1[i][0]=='w' || (str1[i][0]=='c' && str1[i][1]=='h'))
            cout<<str[i]<<"\n";
    }
    for(i=0;i<n;i++)
    {
        if(str1[i][0]=='m' )
            cout<<str[i]<<"\n";
    }
    for(i=0;i<n;i++)
    {
        if(str1[i][0]=='c' && str1[i][1]=='a')
            cout<<str[i]<<"\n";
    }
}
