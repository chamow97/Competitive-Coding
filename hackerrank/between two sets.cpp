#include<bits/stdc++.h>
using namespace std;
int main()
{
	int counter=0,max1=0,min2=10000,j,k,n,m,a[10],b[10],i,c[101];
	cin>>n>>m;
	for(i=0;i<100;i++)
	{
		c[i]=0;
	}
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		max1=max(max1,a[i]);
	}
	for (i = 0; i < m; ++i)
	{
		cin>>b[i];
		min2=min(min2,b[i]);
	}
    for(i=max1;i<=min2;i++)
    {
        bool f=false;
        for(j=0;j<m;j++)
        {
            if(b[j]%i==0)
            {
                f=true;
            }
            else
            {
                f=false;
                break;
            }
        }
        if(f==true)
        {
            for(k=0;k<n;k++)
            {
                if(i%a[k]==0)
                {
                    f=true;
                }
                else
                {
                    f=false;
                    break;
                }
            }
        }
        if(f==true)
            ++counter;
    }
cout<<counter;
}
