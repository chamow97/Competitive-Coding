#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,a[600000],b[600000],i,k,pairs=0,j,temp;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	b[0]=max(a[0],a[1]);
	for(i=1;i<n;i++)
			{
				b[i]=max(b[i-1],a[i]);
			}
				for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			temp=a[i]*a[j];
			long long maximum=0;
			
			if(temp<=max(b[j],b[i]))
			{
				++pairs;
			}
		}
	}
	cout<<pairs;

}