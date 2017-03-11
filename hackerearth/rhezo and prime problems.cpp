#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,maximum = 0;
    long long a[5001];
    cin>>n;
    bool prime[5001];
    long long i,j,counter = 0;

    prime[0] = false;
    prime[1] = true;
    for(i=2;i<=5000;i++)
    {
        prime[i] = true;
    }
    for(i=2;i<=sqrt(5000);i++)
    {
        if(prime[i] == true)
        {
            for(j=i*2 ;j<=100000; j += i)
            {
                prime[j] = false;
            }
        }
    }
    long long dp[5001];
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dp[0] = 0;
    counter = 2;
    for(i=1;i<=n;i++)
    {
        if(prime[counter] == true)
        {
            dp[i] = a[i] + dp[i-1];
            ++counter;
        }
        else
        {

            dp[i] = max(dp[i-1], a[i]);
            if(dp[i] == a[i])
            {
                counter++;
            }
            else
            {
                counter = 2;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        maximum = max(dp[i],maximum);
    }


    cout<<maximum;
}
