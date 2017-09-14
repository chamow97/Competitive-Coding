#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long i,t,n,zeroes=0;
    cin>>t;
    while(t--)
    {
        zeroes=0;
        cin>>n;
        for(i=5;;i*=5)
        {
            if(n/i==0)
                break;

            zeroes+=(n/i);
        }
        cout<<zeroes<<'\n';
    }
}
