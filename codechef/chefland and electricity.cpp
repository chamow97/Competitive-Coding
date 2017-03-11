#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t,i;
	char a[100000];
	long long n,b[100000],wire=0,wire1=0;
	cin>>t;
	while(t--)
	{
		wire=0,wire1=0;
		cin>>n;
		cin>>a;
		for(i=0;i<n;i++)
		cin>>b[i];
		for(i=1;i<n-1;i++)
		{
			if(a[i]=='0')
			{
				wire+=(b[i]-b[i-1]);
			}
		}
		
		if(a[0]=='0')
		{
			wire+=(b[1]-b[0]);
			
		}
		if(a[n-1]=='0')
		{
			wire+=(b[n-1]-b[n-2]);
			
		}
		cout<<wire<<'\n';

	}
		

}
