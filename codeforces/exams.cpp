#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
long long n,i;
long long best = -1;
pair<long long, long long> a[5005];
cin>>n;
for(i=0;i<n;i++)
{
cin>>a[i].first>>a[i].second;
}
sort(a,a+n);
for(i=0;i<n;i++)
{
if(best <= a[i].second)
{
best = a[i].second;
}
else
{
best = a[i].first;
}

}
cout<<best;
}
