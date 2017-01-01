#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long rem,factor,n,m,k,t,i,counter=0,root;
	cin>>t;
	while(t--)
	{
		counter=0;
		cin>>n>>m>>k;
		root=sqrt(k);
		for(i=1;i<=root;i++)
		{
			rem=k%i;
			factor=k/i;
			if(rem==0 && (factor<=m && (k/factor)<=n))
			{
				++counter;
			}
			if(	rem==0 && (factor<=n && (k/factor)<=m) && (factor!=(k/factor)))
			{
				++counter;
			}
			
		}
		cout<<counter<<endl;
	}

}