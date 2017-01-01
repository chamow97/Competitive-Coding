#include<bits/stdc++.h>

using namespace std;

int main()
{
    char str[251];
    long a,i,len=0,temp,factor;
    cin>>a;
    cin>>str;
    if(a==0)
        cout<<str<<'\n';
    else
    {
        temp=0,factor=0;
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            temp=(int)(str[i]-48)%a;
            str[i+1]=(temp*10)+str[i+1];

            factor=(factor*10)+(str[i]/a);

        }
        cout<<factor;

    }
}
