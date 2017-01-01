#include<bits/stdc++.h>

using namespace std;

int main()
{
    long i,n;
    char str[10];
    cin>>n;
    while(n--)
    {
        int k=0;
        cin>>str;

        switch(str[0])
        {
        case 'R':
            int t=0;
            char temp[10];
            for(i=1;str[i]!='C';i++)
                temp[k++]=str[i];

                temp[k]='\0';

            for(i=k+2;i<strlen(str);++i)
            {
                if(str[i]=='\0')
                    break;
                t=(t*10)+((int)(str[i]-48));
            }
            if(t<=26)
            {
                cout<<(char)(t+64)<<temp<<'\n';
            }
            else

            {cout<<(char)((t/26)+64)<<(char)((t%26)+64)<<temp<<'\n';
            }
            break;

            break;

        }
    }
}
