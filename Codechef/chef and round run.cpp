#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long i,j,counter=0,flag=0,t,n,a[100000];
	cin>>t;
	while(t--)
	{
		counter=0;
		flag=0;
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
		{
				for(j=i;;j+=((a[j]+1)%n))
				{
					++flag;
					cout<<j<<'\t';
					if(i==j && flag>1)
					{
						++counter;
						break;
					}
					if(flag==n)
					{
						break;
					}
				}

		}
		cout<<counter<<'\n';
	}
}
