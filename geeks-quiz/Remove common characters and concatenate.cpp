#include <bits/stdc++.h>
using namespace std;

void checkForUncommon(string &firstString, string &secondString)
{
    vector<int> frequencyFirst(26,0);
    vector<int> frequencySecond(26,0);
    int lengthFirst = firstString.length();
    int lengthSecond = secondString.length();
    for(int i = 0; i < lengthFirst; i++)
    {
        frequencyFirst[firstString[i] - 'a']++;
    }
    for(int i = 0; i < lengthSecond; i++)
    {
        frequencySecond[secondString[i] - 'a']++;
    }
    //removing the common from first
    for(int i = 0; i < lengthFirst; i++)
    {
        if(frequencySecond[firstString[i] - 'a'] >= 1)
        {
            firstString[i] = '@';
        }
    }
    for(int i = 0; i < lengthSecond; i++)
    {
        if(frequencyFirst[secondString[i] - 'a'] == 0)
        {
            firstString = firstString + secondString[i];
        }
    }
    lengthFirst = firstString.length();
    string cleanedString = "";
    firstString.erase(remove(firstString.begin(), firstString.end(), '@'), firstString.end());
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string firstString;
	    string secondString;
	    string finalString;
	    cin>>firstString;
	    cin>>secondString;
	    checkForUncommon(firstString, secondString);
	    firstString.length() == 0 ? cout<<-1<<'\n' : cout<<firstString<<'\n';
	}
	return 0;
}