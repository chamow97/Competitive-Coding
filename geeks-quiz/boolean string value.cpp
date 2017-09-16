#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string inputString;
	    cin>>inputString;
	    int stringLength = inputString.length();
	    int currentVal = inputString[0] - '0';
	    for(int i = 1; i < stringLength; i+=2)
	    {
	        switch(inputString[i])
	        {
	            case 'A':
	            currentVal = currentVal & (inputString[i+1] - '0');
	            break;
	            
	            case 'B':
	            currentVal = currentVal | (inputString[i+1] - '0');
	            break;
	            
	            case 'C':
	            currentVal = currentVal ^ (inputString[i+1] - '0');
	            break;
	        }
	    }
	    cout<<currentVal<<'\n';
	}
	return 0;
}