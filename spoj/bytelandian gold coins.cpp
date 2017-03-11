#include<bits/stdc++.h>
#include<map>

using namespace std;
map <int , long long> h;
unsigned long f(unsigned long n)
{

    if(n==0)
        return 0;

    if(h[n]!=0)
        return h[n];
    long long temp=f(n/2)+f(n/3)+f(n/4);
    if(temp>n)
    {
        h[n]=temp;
    }
    else
        h[n]=n;

    return h[n];

}

int main()
{
    int t=10;
    unsigned long  n,i,j;

    while(t--)
    {
        cin>>n;

        cout<<f(n)<<'\n';

    }
}
