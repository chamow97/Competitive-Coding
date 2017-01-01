#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int t=24;
    while(t--)
    {
    int len1,len2,i,j,count,flag=0;
    char a[100],b[100];
    cin>>a;
    cin>>b;
    len1=strlen(a);
    len2=strlen(b);
    for(i=0;i<len1;)
    {

        count=0;
        j=0;
        while(a[i]==b[j])
        {
            ++count;
            ++i;
            ++j;
        }
        if(count==len2)
        {
            cout<<"1\n";
            flag=1;
            break;
        }
        else
        {i-=count;

            i++;
        }
    }
    if(flag==0)
        cout<<"0\n";

    }
}
