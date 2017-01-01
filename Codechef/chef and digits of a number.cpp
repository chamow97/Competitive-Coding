#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long i,t,oneCount=0,zeroCount=0;
	char a[100001];
	cin>>t;
	while(t--)
	{
		oneCount=0;zeroCount=0;
		cin>>a;
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]=='0')
				zeroCount++;
			else
				oneCount++;
		}
		if(strlen(a)==1)
			cout<<"Yes\n";
		else if(zeroCount==1 && oneCount>=1)
			cout<<"Yes\n";
		else if(oneCount==1 && zeroCount>=1)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}