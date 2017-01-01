#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,a[100000],q,b[100000];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>q;
    for(i=0;i<q;i++)
        cin>>b[i];
    sort(a,a+n);
    for(i=0;i<q;i++)
    {
        int low=0,high=n-1,mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(a[i]>a[mid])
            {

            }
        }

    }


}
