#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,n,total=0,minimum=100000000001,x;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        total+=x;
        if(x%2!=0)
        minimum=min(minimum,x);

    }
    if(total%2!=0)
        total=total-minimum;
    cout<<total;
}
