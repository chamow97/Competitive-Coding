#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,a[100000],i,j,m,c[100000],pos,low,high,mid,flag=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(i>=1)
		a[i]=a[i]+a[i-1];
		//cout<<a[i]<<endl;	
	}
	
	cin>>m;
	for(i=0;i<m;i++)
		cin>>c[i];
	for(i=0;i<m;i++)
	{
		
				low=0;
				high=n-1;
				while(low<=high)
				{
					mid=(low+high)/2;
					if(c[i]<a[mid])
					{
						high=mid-1;
						//flag=0;
						pos=mid;
						
					}
					else if(c[i]==a[mid])
					{
						pos=mid;
						break;
					}
					else
					{
						low=mid+1;
						//flag=0;
						pos=mid;
					}
				}
				cout<<mid+1<<'\n';
	}
}