#include <bits/stdc++.h>
using namespace std;

void makeEqual(string &givenNumber, int givenSize, int maxLength)
{
    for(int i = 0; i < maxLength - givenSize; i++)
    {
        givenNumber = '0' + givenNumber;
    }
}

string findSum(string firstNumber, string secondNumber)
{
    int firstSize = firstNumber.length();
    int secondSize = secondNumber.length();
    int maxLength = max(firstSize, secondSize);
    string sumOfNumbers = "";
    makeEqual(firstNumber, firstSize, maxLength);
    makeEqual(secondNumber, secondSize, maxLength);
    int currentCarry = 0;
    for(int i = maxLength - 1; i >= 0; i--)
    {
        int currentSum = (firstNumber[i] - '0') + (secondNumber[i] - '0') + currentCarry;
        sumOfNumbers += (currentSum % 10) + '0';
        currentCarry = currentSum / 10;
    }
    if(currentCarry > 0)
    {
        sumOfNumbers += (currentCarry + '0');
    }
    return sumOfNumbers;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string firstNumber, secondNumber, sumOfNumbers;
        cin>>firstNumber>>secondNumber;
        int checkLength = firstNumber.length();
        string checkNumber = firstNumber;
        sumOfNumbers = findSum(firstNumber, secondNumber);
        if(sumOfNumbers.length() == checkLength)
        {
            reverse(sumOfNumbers.begin(), sumOfNumbers.end());
            cout<<sumOfNumbers<<'\n';
        }
        else
        {
            cout<<checkNumber<<'\n';
        }
    }
	return 0;
}