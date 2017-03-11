#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,q,i,l,counter,r,a[1000000],b[1000000];
	cin>>n>>q;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		counter=0;
		while(a[i]!=1)
		{
			a[i]/=2;
			counter++;
		}
		counter+=1;
		b[i]=counter;
		if(i>0)
		{
			b[i]=b[i]+b[i-1];
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<b[i];
	}
	

	return 0;
}