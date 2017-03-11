#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long t,n,a,b,c,i,j,flag=0,product=0;
  cin>>t;
  while(t--)
  {
      cin>>n;


           flag=0,product=0;
           for(i=(n/3)-1;i>=1;i--)
        {
      a=i;
      b=((-(n*n)+2*n*i)/(-2*(n-i)));
      c=n-a-b;
      if(((a*a)+(b*b)==(c*c)) && b>0 && c>0)
      {
          flag=1;
         //cout<<a<<' '<<b<<' '<<c<<endl;
          product=a*b*c;
            break;

      }
      else flag=0;

  }
  if(flag==0)
  {
    product=-1;
  }
  cout<<product<<"\n";

  }


       //}//

}
