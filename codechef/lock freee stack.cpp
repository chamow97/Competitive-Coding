#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t,n,a[1000][1000],b[10000],i,j,c[10000],total,d[10000],e[10000],maximum=0,k,l;
	cin>>t;
	while(t--)
	{
		total=0;
		k=0;
		int flag=0;
		l=0;
		maximum=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>c[i];
			maximum=max(maximum,c[i]);
			total+=(c[i]);
			for(j=0;j<c[i];j++)
			{
				cin>>a[i][j];
			}
		}
		for(i=0;i<total;i++)
			cin>>b[i];
		for(i=maximum-1;i>=0;i--)
		{
			for(j=0;j<=n-1;j++)
			{
				if(a[j][i]!=0)
				{
					d[k++]=a[j][i];
					//cout<<a[j][i]<<endl;
				}
			}

		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<c[i];j++)
			{
				e[l++]=a[i][j];
				//cout<<a[i][j]<<endl;
			}
		}
		for(i=0;i<total;i++)
		{
			if(b[total-1-i]==d[i])
				flag=1;
			else if(b[total-1-i]==e[i])
				flag=1;
			else
			{
				flag=0;
				break;
			}
		}
		if(flag==0)
			cout<<"No\n";
		else
			cout<<"Yes\n";


	}
}