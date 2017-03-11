#include<iostream>

using namespace std;

long int gcd(int a,int b)
{
   int maximum=max(a,b);
   int minimum=min(a,b);
   if(maximum%minimum==0)
    return minimum;
   else
    return(gcd(minimum,maximum-(minimum*(maximum/minimum))));

}
int main()
{
    long long int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n==m)
            cout<<n<<'\n';
        else if(n==1 || m==1)
            cout<<max(n,m)<<'\n';
        else
            cout<<gcd(n-1,m-1)+1<<'\n';
    }
}
