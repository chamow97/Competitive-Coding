#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t,n,i,j;
	char a[1000][1000],temp;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
		{
			sort(a[i],a[i]+n);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				temp=a[i][j];
				a[i][j]=a[j][i];
				a[j][i]=temp;
			}
		}
		for(i=0;i<n;i++)
		{
			cout<<a[i];
			cout<<endl;
		}
			
	}
}