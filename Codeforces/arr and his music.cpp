#include<bits/stdc++.h>

using namespace std;

int main()
{

	int b[100],i,n,k,j,l=0,a[100],pos[100];
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	pos[0]=0;
	sort(a,a+n);
	while(k>0)
	{
	for(i=0;i<n;i++)
	{
		k-=a[i];
		for(j=0;j<n;j++)
			if(a[i]==b[j])
				pos[l++]=j+1;
}}
cout<<l<<'\n';
for(i=0;i<l;i++)
	cout<<pos[l]<<' ';
}

















