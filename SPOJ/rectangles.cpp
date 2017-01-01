#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long count=0,i,j,n,sum=0;
    cin>>n;
    for(i=1;i<=sqrt(n);i++)
    {
        for(j=i+1;i*j<=n;j++)
        {
            count++;
        }

    }
    count+=sqrt(n);

    cout<<count;


}
