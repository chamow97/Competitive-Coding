#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,n,m;
	cin>>n>>m;
	if(n==1 || m==1)
	{
		cout<<max(n-1,m-1)<<endl;
	}
	else
	{
		a=(n-1)+(n*(m-1));
	b=(m-1)+(m*(n-1));
	cout<<min(a,b)<<endl;

	}
	
}