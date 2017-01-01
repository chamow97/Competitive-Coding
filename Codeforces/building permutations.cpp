#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long temp,n,a[300000],count=0,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		temp=a[i]-(i+1);
		if(temp<0)
			temp=(temp*(-1));
		count+=temp;
	}
	cout<<count;
}