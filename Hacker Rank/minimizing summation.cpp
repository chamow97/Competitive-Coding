#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,j,k,a[100000],i,sum1=0,sum2=0,minimum=1e18,pos;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;i<k;i++)
    {
        sum1+=(pow(a[i],2));
        sum2+=(a[i]);
    }
    minimum=min(minimum,ll((2*k*sum1)-(2*pow(sum2,2))));


        for(j=k;j<i+k;j++)
        {
            sum1+=((a[j]*a[j]-a[j-k]*a[j-k]));
            sum2+=(((a[j]-a[j-k])));
        }
        minimum=min(minimum,ll((2*k*sum1)-(2*sum2*sum2)));
    cout<<minimum;

}
