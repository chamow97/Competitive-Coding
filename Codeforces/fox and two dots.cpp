#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n,m,i,j,flag=0,counter=0;
	cin>>n>>m;
	char a[50][50];
	for(i=0;i<n;i++)
	{
			cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]!='#')
			{
				flag=0;
				if(a[i][j]==a[i+1][j])
					flag++;
				if(a[i][j]==a[i][j+1])
					flag++;
				if(a[i][j]==a[i-1][j])
					flag++;
				if(a[i][j]==a[i][j-1])
					flag++;
				if(flag<2)
				{
					a[i][j]='#';
					i=0;
					j=0;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]!='#')
				++counter;
		}
	}
	if(counter>1)
		cout<<"Yes";
	else
		cout<<"No";


}
