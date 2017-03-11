#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k,a[100000],i,counter=0;
    bool b[100000];
    float sum=0.0;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
   for(i=1;i<n;)
   {
       ++counter;
       i+=(k*2);
       i++;
   }
   if(a[1]-a[0]>k)
   {
       ++counter;
   }
   if(a[n-1]-a[n-1]>k)
   {
       ++counter;
   }
   cout<<counter;

}
