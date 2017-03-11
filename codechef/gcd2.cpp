#include<bits/stdc++.h>
using namespace std;
long gcd(long long a,long long b)
{if(b==0)
  return a;
  else
  return gcd(b,a%b);
}
int main()
{long result,len=0,i,t,a,remainder=0;
 char b[1000];
 cin>>t;
 while(t--)
 {
 remainder=0;
 len=0;
 cin>>a>>b;
 if(a==0)
 { cout<<b<<'\n'; continue;        }
 len=strlen(b);
 for(i=0;i<len;i++)
 { remainder=(remainder*10)+(b[i]-'0');
            remainder=remainder%a;}
 result=gcd(a,remainder);
 cout<<result<<'\n';}}
