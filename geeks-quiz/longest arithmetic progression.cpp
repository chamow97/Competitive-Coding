#include <bits/stdc++.h>
using namespace std;

int longestAP(int sizeOfArray, vector<int> &inputArray)
{
    int longestAPLength = 2;
    if(sizeOfArray <= 2)
    {
        return sizeOfArray;
    }
    int dp[sizeOfArray+1][sizeOfArray+1];
    //an AP starting at some pt and ending at n-1 is always of size 2
    for(int i = 0; i < sizeOfArray; i++)
    {
        dp[i][sizeOfArray-1] = 2;
    }
    //we fix a mid element and search two sides for i,k where arr[i] + arr[k] = 2*arr[j]
    
    for(int j = sizeOfArray-2; j >= 1; j--)
    {
        int i = j-1;
        int k = j+1;
        while(i >= 0 && k < sizeOfArray)
        {
            if(inputArray[i] + inputArray[k] < 2 * inputArray[j])
            {
                k++;
            }
            else if(inputArray[i] + inputArray[k] > 2 * inputArray[j])
            {
                dp[i][j] = 2;
                i--;
            }
            else
            {
                dp[i][j] = 1 + dp[j][k];
                longestAPLength = max(longestAPLength, dp[i][j]);
                i--;
                k++;
            }
        }
        while(i >= 0)
        {
            dp[i][j] = 2;
            i--;
        }
    }
    return longestAPLength;
}

int main() {
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        cin>>sizeOfArray;
        vector<int> inputArray(sizeOfArray, 0);
        sort(inputArray.begin(), inputArray.end());
        for(int i = 0; i < sizeOfArray; i++)
        {
            cin>>inputArray[i];
        }
        cout<<longestAP(sizeOfArray, inputArray)<<'\n';
    }
	return 0;
}