#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,m,value;
	cin>>n>>m;
	if(m%n==0)
		cout<<"0";
	else
	{
		value=n-(m%n);
		cout<<value;
	}
}
