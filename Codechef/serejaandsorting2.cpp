#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[1000],j=0,pos[500];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a,a+n);
	for(i=0;i<=n/2;i++)
	{
		if(a[i]!=b[i])
		{
			pos[j++]=i+1;

		}
	}

}