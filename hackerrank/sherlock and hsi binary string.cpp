#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long m,n;
	cin>>m>>n;
	if(m<=2)
	{
		cout<<m<<" "<<n-1;
	}
	else
	{
		cout<<m-1<<" "<<n;
	}
}