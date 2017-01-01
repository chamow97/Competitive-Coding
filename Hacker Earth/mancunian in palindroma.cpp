#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long counter=0,n,l,i,j,a[26],b[26];
    char str[51];
    cin>>n>>l;
    for(i=0;i<n;i++)
    {
        bool found=false;
        for(j=0;j<26;j++)
        {
            a[j]=0;
            b[j]=0;
        }
        cin>>str;
        l=strlen(str);
        for(j=0;j<l;j++)
        {
            a[str[j]-97]++;
        }
        for(j=0;j<l/2;j++)
        {
            str[j]=str[l-j-1];
        }
        for(j=0;j<l;j++)
        {
            b[str[j]-97]++;
        }
        for(j=0;j<26;j++)
        {
            if(a[j]==b[j])
            {
                found=true;
            }
            else
            {
                found=false;
                break;
            }
        }
        if(found==true)
        {
            ++counter;
        }



    }
    cout<<counter;
}
