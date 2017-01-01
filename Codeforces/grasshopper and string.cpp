#include<bits/stdc++.h>
using namespace std;
int main()
{
	char str[101];
	int len,i,maxi=0,lastpos=-1;
	cin>>str;
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' || str[i]=='Y')
		{
			maxi=max(maxi,i-lastpos);
			lastpos=i;
		}
	}
	maxi=max(maxi,len-lastpos);
	cout<<maxi;
}
