#include<bits/stdc++.h>
using namespace std;
long long int a,n,k,i;
long int p[101]={0};
int main()
{
cin>>a>>n>>k;
for(int i=0;i<k;++i)
{
p[i]=a%(n+1);
a/=n+1;
cout<<p[i]<<" ";
}
cout<<endl;
return 0;
}
