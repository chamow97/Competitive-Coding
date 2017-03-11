#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	long long i,n,a[10000],b[100000],prod=0;
	cin>>t;
	while(t--)
	{
		prod=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i]>>b[i];
		}
		sort(a,a+n);
		sort(b,b+n);
		for(i=n-1;i>=0;i--)
		{
			prod+=(a[i]*b[i]);
		}
		cout<<prod<<"\n";
	}
}