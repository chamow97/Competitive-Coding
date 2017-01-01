#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,n,m;
	char a[100][100];
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]=='-')
				cout<<'-';
			else if(i%2==0 && j%2==0)
			{
				cout<<'B';
			}
			else if(i%2==0 && j%2==1)
			{
				cout<<'W';
			}
			else if(i%2==1 && j%2==0)
			{
				cout<<'W';
			}
			else
				cout<<'B';
		}
		cout<<'\n';
	}
}