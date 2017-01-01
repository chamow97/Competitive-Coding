#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long pos,minimum=1000000000,n,k,a[500001],b[500001],i;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	b[0]=0;
	b[1]=a[1];
	
	for(i=2;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
		
	}
	
	for(i=n;i>=k;i--)
	{
		if(minimum>=(b[i]-b[i-k]))
		{
			minimum=(b[i]-b[i-k]);
			pos=i;
		}
		
	}
	cout<<endl<<pos+1-k;
	
	
}