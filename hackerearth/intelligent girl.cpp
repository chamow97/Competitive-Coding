#include <iostream>
using namespace std;
 
int main()
{
    string s;
    cin>>s;
    int len = s.length();
    int i,j;
    int dp[10001];
    dp[0] = 0;
    if(int(s[len-1] - 48) % 2 == 0)
    {
        dp[1] = 1;
    }
    else
    {
        dp[1] = 0;
    }
    for(i=len-2;i>=0;i--)
    {
        if(int(s[i]  - 48) % 2 == 0)
        {
            dp[len-i] = 1 + dp[len-i-1];
        }
        else
        {
            dp[len-i] = dp[len-i-1];
        }
    }
    for(i=len-1; i>=0; i--)
    {
        cout<<dp[i+1]<<" ";
    }
    return 0;
}