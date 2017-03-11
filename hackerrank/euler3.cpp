#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,i=0,factor=0,t;
	cin>>t;
	while(t--)
	{
		factor=0;
		cin>>n;

	while(n%2==0)
	{
		factor=2;
		n=n/2;
	}
	for(i=3;i<=sqrt(n);i+=2)
	{
		while(n%i==0)
		{
			n=n/i;
			factor=max(factor,i);
		}

	}
	if(n>2)
		factor=max(n,factor);

	cout<<factor<<'\n';

	}
	
}