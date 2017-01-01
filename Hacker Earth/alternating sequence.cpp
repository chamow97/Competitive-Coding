#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long i,n,a[5000],flag=1,counter=0;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	if(a[0]<0)
			flag*=(-1);
		else
			flag=1;
	for(i=1;i<n;i++)
	{
		if(flag==-1 && a[i]>0 )
		{
			flag=1;
			++counter;
		}
		else if(flag==1 && a[i]<0)
		{
			flag=-1;
			++counter;
		}

	}
	cout<<counter+1<<'\n';
}