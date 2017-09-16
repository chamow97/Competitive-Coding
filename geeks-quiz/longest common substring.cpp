#include <iostream>
using namespace std;

int longestCommonSubstring(string firstString, int lengthOne, string secondString, int lengthTwo)
{
    int dp[lengthOne+1][lengthTwo+1];
    int lengthOfCommonSubstring = 0;
    for(int i = 0; i < lengthOne+1; i++)
    {
        for(int j = 0; j < lengthTwo+1; j++)
        {
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i < lengthOne+1; i++)
    {
        for(int j = 1; j < lengthTwo+1; j++)
        {
            if(firstString[i-1] == secondString[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 0;
            }
            lengthOfCommonSubstring = max(lengthOfCommonSubstring, dp[i][j]);
        }
    }
    return lengthOfCommonSubstring;
}

int main() {
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    int lengthOne, lengthTwo;
	    string firstString, secondString;
	    cin>>lengthOne>>lengthTwo;
	    cin>>firstString>>secondString;
	    cout<<longestCommonSubstring(firstString, lengthOne, secondString, lengthTwo)<<'\n';
	}
	return 0;
}