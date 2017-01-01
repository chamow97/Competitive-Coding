#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int getlongstring(int i,int j,char str[10001],int a[])
{
    int l,k=0;
    bool found=false;
    char temp[10000];
    for(l=0;l<strlen(str);l++)
    {
        if(str[l]==char(97+i) || str[l]==char(97+j))
        {
            temp[k]=str[l];
            k++;
        }
    }

    int len=strlen(temp);

    if(len==2)
    {
        if(temp[0]!=temp[1])
            found=true;
        else
            found=false;
    }
    else if(len==1)
    {
        found=false;
    }
    else
    {
        if(len%2==0)
    {
        for(i=0;i<len-2;i++)
        {
            if(temp[i]==temp[i+2])
            {
                found=true;
            }
            else
            {
                found = false;
                break;
            }
        }
    }
    else
    {
        for(i=0;i<len/2;i++)
        {
            if(temp[i]==temp[len-1-i])
            {
                found=true;
            }
            else
            {
                found=false;
                break;
            }
        }
    }

    }

    if(found==true)
        return len;
    else
        return 0;
}
int main()
{
    char str[10001];
    int len,i,j,a[26]={0},counter,maximum=0;
    cin>>len;
    cin>>str;
    for(i=0;i<len;i++)
    {
        if(a[str[i]-97]==0)
        a[str[i]-97]++;
    }
    for(i=0;i<26;i++)
    {
        if(a[i]!=0)
        {
            for(j=i+1;j<26;j++)
            {
                if(a[j]!=0 && i!=j)
                {
                    counter=getlongstring(i,j,str,a);
                    maximum=max(counter,maximum);
                }
            }

        }

    }

    cout<<maximum;
    return 0;
}
