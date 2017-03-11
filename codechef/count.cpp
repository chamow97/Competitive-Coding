#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int t,q;
    cin>>t;
    long int n,i,j;
    char str[100000],f,type[5];

    while(t--)
    {
        cin>>n>>q;
        cin>>str;
        for(i=0;i<q;i++)
        {
            long int count=0;
            cin>>f>>type;
            for(j=0;j<strlen(str);j++)
            {
                if(str[j]==f)
                    ++count;

            }

            if(type[0]=='e' && count%2==0)
                cout<<"yes\n";
            else if(type[0]=='o' && count%2!=0)
                cout<<"yes\n";
            else if(type[0]=='o' && count%2==0)
                cout<<"no\n";
            else
                cout<<"no\n";
        }
    }
}
