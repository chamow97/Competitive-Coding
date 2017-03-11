#include<bits/stdc++.h>

using namespace std;

int main()
{
	long i,j,happy=0,sum=0;
	long long n,m;
	cin>>n>>m;
	long a[n],b[m][3];
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<m;i++)
		cin>>b[i][0]>>b[i][1]>>b[i][2];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if((j+1)>=b[i][0] && (j+1)<=b[i][1])
			{
				sum+=a[j];
			}

		}
		if(sum>=b[i][2])
			happy++;
		sum=0;
	}
	cout<<happy<<'\n';

}