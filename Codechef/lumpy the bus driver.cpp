#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long sum=0,i,t,n,p,q,a[100000];
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n>>p>>q;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		i=0;
		for(i=0;i<n;i++)
		{
			if(p>0 && q>0)
			{
				q=(q-(a[i]/2));
				p=(p-(a[i]%2));
				if(p>=0 && q>=0)
				++sum;
				
			}
			else if(p)
		}
	}
}