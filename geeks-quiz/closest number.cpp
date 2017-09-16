#include <iostream>
using namespace std;

int findClosest(int n, int m)
{
    int quotient = n/m;
    int lowerBound = m*(quotient);
    int upperBound = n*m > 0 ? m*(quotient+1) : m*(quotient-1);
    if(abs(n - lowerBound) < abs(upperBound - n))
    {
        return lowerBound;
    }
    else
    {
        return upperBound;
    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m;
	    cin>>n>>m;
	    cout<<findClosest(n, m)<<'\n';
	}
	return 0;
}