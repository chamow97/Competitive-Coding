#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long i,t,n,sum=0,flag1=0,flag2=0;
	float avg=0.0;
	int a[100000];
	cin>>t;
	while(t--)
	{
		avg=0.0;
		sum=0;
		flag1=0;
		flag2=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]<=2)
				flag1=1;
			if(a[i]==5)
				flag2=1;
			sum+=a[i];

		}
		avg=(sum*(1.0))/(n*(1.0));
		if(avg>=4.0 && flag1==0 && flag2==1)
			cout<<"Yes\n";
		else
			cout<<"No\n";

	}
}