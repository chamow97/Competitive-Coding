//template by chamow

#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
typedef long long ll;
int main()
{
    ll n,m,i,j,pairs=0,limit=100000;
    vector<int> prime;
    bool arr[limit];
    cin>>n;
    cin>>m;
    for(i=2;i<(100000);i++)
    {
        arr[i]=false;
    }
    for(i=2;i<sqrt(100000);i++)
    {   if(arr[i]==false)
        {
            for(j=i*2;j<100000;j+=i)
            {
                arr[j]=true;
            }
        }
    }
    for(i=3;i<=min(m,99999ll);i++)
    {
            if(arr[i]==false)
            prime.pb(i);
    }
    //limit=n;
int    low=limit;
int    high=2*limit;
if(high>=m)
{
    high=m;
}
    while(low<m)
    {
        bool mark[limit+1];
        for(i=2;i<limit;i++)
        {
            mark[i]=false;
        }
        for(i=0;i<prime.size();i++)
        {
            int lowLim=floor(low/prime[i])*prime[i];
            if(lowLim<low)
            {
                lowLim+=prime[i];
            }
            for(j=lowLim;j<high;j+=prime[i])
            {
                mark[j-low]=true;
            }
        }
        for(i=low;i<high;i++)
        {
            if(mark[i-low]==false)
            {
                prime.pb(i);
            }
        }
        low=low+limit;
        high=high+limit;
        if(high>=m)
        {
            high=m;
        }
    }
   i=0;
   while(prime[i]<n)
   {
       i++;
   }
   for(j=i;j<prime.size()-1;j++)
   {
       if(prime[j+1]-prime[j]==2)
       {
           ++pairs;
       }
       if(j>m)
       {
           break;
       }
   }
   cout<<pairs;
    return 0;
}
