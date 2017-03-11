#include<bits/stdc++.h>
using namespace std;

int main()
{
	char str[100010];
	int j,q,i,a[100005],counter=0,r,l;
	cin>>str;
	cin>>q;
	a[0]=0;
	for(i=1;i<strlen(str);i++)
	{
		
		if(str[i]==str[i-1])
		{
			a[i]=1;
		}
		else
			a[i]=0;
		a[i]=a[i]+a[i-1];
	}
	for(i=0;i<q;i++)
	{
		counter=0;
		cin>>l>>r;
		cout<<a[r-1]-a[l-1]<<'\n';
	}

}