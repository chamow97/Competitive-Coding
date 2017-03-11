#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long q,n,a[256][256],i,j;
	long long sum=0,maximum=0;
	cin>>q;
	while(q--)
	{
		sum=0;
		cin>>n;
		n*=2;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}
		for(i=0;i<n/2;i++)
		{
			for(j=0;j<n/2;j++)
			{
				maximum=0;
				maximum=max(a[i][j],maximum);
				maximum=max(a[i][n-1-j],maximum);
				maximum=max(a[n-1-i][j],maximum);
				maximum=max(a[n-1-i][n-1-j],maximum);
				sum+=(maximum);
			}
		}
		cout<<sum<<'\n';

	}
}