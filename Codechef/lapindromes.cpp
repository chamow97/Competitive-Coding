#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int i,j,sum1=0,sum2=0,flag=0;
        char s[1005];
        cin>>s;
        for(i=0;i<=(strlen(s)-1)/2;i++)
            {  flag=0;
                sum1+=(int)s[i];
              for(j=strlen(s)/2;j<strlen(s);j++)
            {

                if(s[j]==s[i])
                    {flag=1;
                    break;}
                else
                {
                    flag=0;
                }


            }
            if(flag==0)
                break;

            }
            for(j=strlen(s)/2;j<strlen(s);j++)
                sum2+=(int)s[j];
            if(flag==1 && sum1==sum2)
                cout<<"YES\n";
            else
                cout<<"NO\n";


    }
}
