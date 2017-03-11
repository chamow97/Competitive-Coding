#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long unsigned int result,i,t,n,a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n=n-1;
        a=n/3;
        b=n/5;
        c=n/15;
        result=(3*(a+(a*a))+5*(b+(b*b))-15*(c+(c*c)));
        cout<<result/2<<'\n';
        
    }
}
