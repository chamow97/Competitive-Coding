#include<bits/stdc++.h>

using namespace std;
long long counter=0;

long long find(long long n)
{
    long long temp,sum1=1,sum=0;

    if(sum1==n && counter!=1)
        return -1;
    else
    {
        sum=0;
        while(n)
        {
            temp=n%10;
            sum+=(temp*temp);
            n/=10;
        }
        if(counter==0)
            sum1=sum;
        ++counter;
        find(sum);
        return counter;
    }
}

int main()
{
    long long n,ans;
    cin>>n;
    ans=find(n);
    cout<<ans;
}
