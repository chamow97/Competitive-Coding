#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long i,m,n,a[1000],b[2000],value=0,finalval=0;
	cin>>n;
	int l=0,o=1,val=0;
	b[0]=1;
	while(value<=1000)
	{
		value=o+l;
		//cout<<value<<endl;
		b[value]=1;
		l=o;
		o=value;
		
	}

	while(n--)
	{
		finalval=0;
		val=0;
		cin>>m;
		for(i=0;i<m;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<m;i++)
		{
			if(b[i+1]==1)
			{
				val=(a[i]*(i+1));
				//cout<<val<<endl;				
			}
			else
			{
				val=a[i];
			}
			val=val%100;
				finalval+=val;
		}
		cout<<(finalval/m)<<endl;
	}
}