#include <bits/stdc++.h>
using namespace std;

vector<int> result;

void multiply(int current)
{
    int currentCarry = 0;
    for(int i = 0; i < result.size(); i++)
    {
        int currentValue = currentCarry + (result[i] * current);
        result[i] = currentValue % 10;
        currentCarry = currentValue / 10;
    }
    while(currentCarry != 0)
    {
        result.push_back(currentCarry % 10);
        currentCarry /= 10;
    }
}

void factorial(int n)
{
    result.push_back(1);
    for(int i = 2; i <= n; i++)
    {
        multiply(i);
    }
}

int main() {
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        result.clear();
        int n;
        cin>>n;
        factorial(n);
        for(int i = result.size()-1; i >= 0; i--)
        {
            cout<<result[i];
        }
        cout<<'\n';
    }
	return 0;
}