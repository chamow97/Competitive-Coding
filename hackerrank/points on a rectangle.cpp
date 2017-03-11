#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,q,n,a[10],b[10],visited[10];
	cin>>q;
	while(q--)
	{
		int maxrow1=-100000,minrow1=100000,maximum,minimum;
				int maxrow=-100000,minrow=100000;
		cin>>n;
		bool found=false;
		for(i=0;i<n;i++)
		{
			cin>>a[i]>>b[i];
			maxrow=max(maxrow,a[i]);
			maxrow1=max(maxrow1,b[i]);
			minrow=min(minrow,a[i]);
			minrow1=min(minrow1,b[i]);
		}
		
		//minimum=min(minrow1,minrow);
		//maximum=max(maxrow,maxrow1);
		//cout<<minimum<<maximum<<endl;
		for(i=0;i<n;i++)
		{
			if(a[i]==minrow && b[i]<=maxrow1 && b[i]>=minrow1)
			{
				found=true;
			}
			else if(a[i]==maxrow && b[i]<=maxrow1 && b[i]>=minrow1)
			{
				found=true;
			}
			else if(b[i]==maxrow1 && a[i]<=maxrow && a[i]>=minrow)
			{
				found=true;
			}
			else if(b[i]==minrow1 && a[i]<=maxrow && a[i]>=minrow)
			{
				found=true;
			}
			else
			{
				found=false;
				break;
			}

		}
if(found==false)
{
	cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";
	}
}
}