#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long value=0,n,a[100000],q,b[100000],i,j;
	cin>>n;
	for(i=0;i<=n;i++)
		cin>>a[i];
	cin>>q;
	for(i=0;i<q;i++)
		cin>>b[i];
	for(i=0;i<q;i++)
	{
		value=0;
		for(j=0;j<=n;j++)
		{
			value+=((a[j])*(pow(b[i],j)));
		}
		cout<<value%786433<<'\n';
	}
	
}