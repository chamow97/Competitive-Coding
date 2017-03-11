#include<bits/stdc++.h>
using namespace std;
int main()
{

	char str[100001];
	bool found=false;
	long int i=0;
	cin>>str;
	long long len=strlen(str);
	if(len==1)
	{
		cout<<'0';
	}
	else
	{
		if(str[len-1]=='E')
		{
			cout<<len-1;
		}
		else if(str[0]=='E')
		{
			cout<<'0';
		}
		else
		{
			for(i=len-3;i>=1;i--)
			{
				if(str[i]==str[i-1]&&str[i]==str[i+1] && str[i]=='E')
				{
					found=true;
					break;
				}
				else
				{
					found=false;
				}
			}
			if(found==false)
			{
				for(i=len-1;i>=0;i--)
				{
					if(str[i]=='E')
					{
						cout<<i;
						break;
					}
				}
			}
			else if(found==true)
			{
				for(i=1;i<len-1;i++)
				{
					if(str[i]==str[i-1]&&str[i]==str[i+1] && str[i]=='E')
					{
						cout<<i;
						break;
					}
				}
			}
		}
	}
}