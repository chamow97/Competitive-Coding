#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    long int t,sum=0,i;
    char str[10000];
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>str;
        for(i=0;i<strlen(str);i++)
        {
            sum+=(int)(str[i]);

        }
        cout<<(char)(sum/(strlen(str)))<<"\n";
    }
}
