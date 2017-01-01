#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long i,j,count=0,t,n,a[114729];
	cin>>t;
	while(t--)
	{
		count=0;
		cin>>n;
		if(n==10000)
			cout<<"104729\n";

		else
		{
			for(i=2;i<=sqrt(114729);i++)
		{
			if(a[i]==0)
			{
				
				for(j=i*2;j<=114729;j+=i)
				{
					a[j]=1;
				}

			}	
			
		}
		for(i=2;i<=114729;i++)
		{
			if(a[i]==0)
			{
				++count;
			}
			if(count==n)
				break;
		}
		cout<<i<<'\n';

		}
		

		}
		
	
}