#include <bits/stdc++.h>
using namespace std;

int findMissingNumber(int sizeOfArray, vector<int> &inputArray)
{
    if(inputArray[sizeOfArray - 1] != sizeOfArray + 1)
    {
        return sizeOfArray + 1;
    }
    if(inputArray[0] != 1)
    {
        return 1;
    }
    int missingNumber = 0;
    int low = 0, high = sizeOfArray - 1, mid;
    while(low <= high)
    {
        mid = (low + high + 1)/2;
        if(inputArray[mid] == mid+1)
        {
            low = mid + 1;
        }
        else
        {
            missingNumber = mid;
            high = mid - 1;
        }
    }
    return missingNumber + 1;
}

int main() {
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    int sizeOfArray;
	    cin>>sizeOfArray;
	    --sizeOfArray;
	    vector<int> inputArray(sizeOfArray, 0);
	    for(int i = 0; i < sizeOfArray; i++)
	    {
	        cin>>inputArray[i];
	    }
	    sort(inputArray.begin(), inputArray.end());
	    cout<<findMissingNumber(sizeOfArray, inputArray)<<'\n';
	}
	return 0;
}