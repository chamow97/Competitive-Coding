#include<bits/stdc++.h>

using namespace std;

int main()
{
	int sum,i,j,t,n,k,a[200],b[200],l=0;
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n>>k;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			b[i]=0;
		}
		for(i=0;i<n;i++)
		{
			  	if(a[i]!=0)
			  { b[i]+=1;
			  	for(j=i+1;j<n;j++)
				{
					if(a[i]==a[j])
					{
						a[j]=0;
						b[i]+=1;
					}
				}
			}
		}
		
		for(i=0;i<n;i++)
		{
			if((b[i])>=k && a[i]!=(i+1))
			{
				sum++;
			}
		}
		cout<<sum<<'\n';
	}
}