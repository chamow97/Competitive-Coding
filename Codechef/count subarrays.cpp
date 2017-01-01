#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long sum,i,n,t,a[100001],b[100001];
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		b[0]=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]>=a[i-1])
			{
				b[i]=b[i-1]+1;
			}
			else
			{
				b[i]=1;
			}
		}
		for(i=1;i<=n;i++)
		{
			sum+=(b[i]);
		}
		cout<<sum<<endl;
	}

}