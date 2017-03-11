#include<bits/stdc++.h>
using namespace std;
int main()
{

	int a[2][5],i,j,stepsTemp=0,stepsFinal=0;
	for(i=0;i<2;i++)
	{
		for(j=0;j<5;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=0;i<5;i++)
	{
		stepsTemp=abs(a[0][i]-a[1][i]);
		if(stepsTemp/5>=1)
		{
			stepsTemp=10-stepsTemp;
		}
		stepsFinal+=(stepsTemp);
	}
	cout<<stepsFinal;
}