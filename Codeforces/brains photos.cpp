#include<bits/stdc++.h>
using namespace std;

int main()
{
	int flag=0;
	long long i,j,n,m;
	cin>>n>>m;
	char str[100][100];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>str[i][j];
			
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(str[i][j]=='B' || str[i][j]=='W' || str[i][j]=='G')
			{
				flag=1;
			}
			else
			{
				flag=0;
				goto flags;
			}
		}
	}
	flags:
	if(flag==0)
	{
		cout<<"#Color";
	}
	else
		cout<<"#Black&White";


}