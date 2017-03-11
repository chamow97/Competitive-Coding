#include<iostream>

using namespace std;

int main()
{
    long long t,n,result;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n*=4;
        result=(n*(n-1)*(n-2))/6;
        cout<<result<<"\n";

    }
}
