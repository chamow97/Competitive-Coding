#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,a[1000],i,j,k;
	long sereja=0,dima=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	i=0;
	j=n-1;
	k=0;
	while(i<=j)
	{
		if(k%2==0)
		{
			sereja+=(max(a[i],a[j]));
		}
		else
		{
			dima+=(max(a[i],a[j]));
		}
		if(max(a[i],a[j])==a[i])
			++i;
		else
			--j;
		k++;
	}
	cout<<sereja<<' '<<dima;
}