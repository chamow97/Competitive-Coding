#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long divide,i,n,a[500001],b[500001];
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	b[0]=0;
	b[1]=a[1];
	divide=n/3;
	for(i=2;i<=n;i++)
	{
		b[i]=a[i]+a[i-1];
	}


}