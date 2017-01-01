#include<bits/stdc++.h>
using namespace std;
int main()
{
long long n,i,t,t1,arr[5000],brr[5000],maxa = -100000, maxb = -100000;
map<int,int> a;
map<int,int> b;
cin>>n;
for(i=0; i<n; i++)
{
cin>>arr[i]>>brr[i];
maxa = max(maxa, arr[i]);
maxb = max(maxb, brr[i]);
a[arr[i]] = brr[i];
b[brr[i]] = arr[i];
}
if(n == 1)
{
cout<<min(maxa, maxb);
}
else
{
bool flag1 = false, flag2 = false;
for(i=0; i<n; i++) 
{
if(b.at(brr[i]) == arr[i])
{
flag1 = true;
}
else
{
flag1 = false;
break;
}
}
for(i=0; i<n; i++)
{
if(a.at(arr[i]) == brr[i])
{
flag2 = true;
}
else 
{
flag2 = false;
}
}
if(flag1 == true)
{
cout<<maxa;
}
else
{
cout<<maxb;
}

}

}
