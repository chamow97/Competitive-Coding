#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long flag=0,t,n,a[100000],i,maximum,maxsofar,non_cont,minimum=0;
	cin>>t;
	while(t--)
	{
		flag=1;
		minimum=-10000;
		non_cont=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]<0 && flag!=0)
				flag=1;
			if(a[i]>0)
				{
					non_cont+=(a[i]);
					flag=0;
				}
				minimum=max(minimum,a[i]);
		}
		maximum=a[0];
		maxsofar=a[0];
		for(i=1;i<n;i++)
		{
			
			
		}
		    if(flag==1)
			cout<<minimum<<' '<<minimum<<endl;
		else
		cout<<maxsofar<<' '<<non_cont<<endl;


	}
}