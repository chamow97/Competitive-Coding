#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[500000];
	long long modlo=1000000007,counter=0,m,i,a[26],maximum=0;
	bool isSame=false;
	cin>>s;
	cin>>m;
	for(i=0;i<strlen(s);i++)
	{
		a[int(s[i]-97)]++;
	}
	maximum=a[0];
	for(i=1;i<26;i++)
	{
		if(a[i]==a[i-1] || a[i]==0)
			{
				isSame=true;
				if(a[i]!=0)
				++counter;
			}
		else
		{
			isSame=false;
			counter=1;
			break;
		}
	}
	if(isSame==true)
	{
		cout<<(m/(counter+1))%modlo;
	}
	else
	{
		cout<<(m/strlen(s))%modlo;
	}
	
}