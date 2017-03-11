#include<bits/stdc++.h>
using namespace std;
int main()
{
long long n,k,high,low,mid,ans;
cin>>n>>k;
low = 0;
high = pow(2,n) ;
mid = 0;
while(low < high)
{
mid = (high + low)/2;
if(k == mid)
{
ans = n;
break;
}
else if(k > mid)
{
k = high - k;
}
else
{
high = ((high)/2);
n--;
}
}
cout<<ans;
}
