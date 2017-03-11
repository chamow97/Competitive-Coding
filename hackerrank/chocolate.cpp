#include<bits/stdc++.h>

using namespace std;
int main()
{
long long t,n,c,m,chocolate=0,wrapper=0,temp;
cin>>t;
while(t--)
{
  wrapper=1000; 
  chocolate=0;
cin>>n>>c>>m;
while(wrapper>1)
{
  temp=n/c;
chocolate+=(temp);
wrapper+=temp;
chocolate+=(wrapper/m);
wrapper=((wrapper%m)+(wrapper/m));
n=0;
}
cout<<chocolate<<'\n';
}


}