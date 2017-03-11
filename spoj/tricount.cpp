#include<bits/stdc++.h>

using namespace std;

int main()
{
   long long unsigned int t,n,count=0;
    cin>>t;
    while(t--)
    {
        count=0;
        cin>>n;
        if(n%2==0)
        count=(n*(n+2)*((2*n)+1))/8;
        else
            count=((n*(n+2)*((2*n)+1))-1)/8;

        cout<<count<<'\n';
    }
}
