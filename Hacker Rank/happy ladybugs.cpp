#include<bits/stdc++.h>
using namespace std;
int main()
{
    int g,n,i,us=0,a[26];
    char str[102];
    cin>>g;
    while(g--)
    {
        bool condition=false;
        for(i=0;i<26;i++)
        {
            a[i]=0;
        }
        us=0;
        cin>>n;
        cin>>str;
        for(i=0;i<n;i++)
        {
            if(str[i]=='_')
            {
                us++;
            }
            else
            {
                a[str[i]-65]++;
            }
        }
       if(us==0)
       {

           for(i=0;i<n;i++)
           {
               if(str[i]==str[i+1] && i!=n-1)
               {
                   condition=true;
               }
               else if(str[i]==str[i-1] && i!=0)
               {
                   condition=true;
               }
               else
               {
                   condition=false;
                   break;
               }
           }

       }
       else
       {
           if(us==n)
           {
               condition=true;
           }
           else
           {
               for(i=0;i<26;i++)
               {
                   if(a[i]!=1)
                   {
                       condition=true;
                   }
                   else
                   {
                       condition=false;
                       break;
                   }
               }
           }


       }
       if(condition==true)
           {
               cout<<"YES\n";
           }
           else
           {
               cout<<"NO\n";
           }
}
}
