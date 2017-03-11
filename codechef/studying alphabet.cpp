#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[26];
	char str[30];
	long long n,i;
	cin>>str;
	for(i=0;i<26;i++)
		arr[i]=0;
	for(i=0;i<strlen(str);i++)
	{
		arr[int(str[i]-97)]=1;
	}
	
	cin>>n;
	while(n--)
	{
		int flag=0;
		char str1[30];
		cin>>str1;
		for(i=0;i<strlen(str1);i++)
		{
			
			if(arr[int(str1[i]-97)]==0)
				{
					flag=0;
					break;
				}
			else
			{
				flag=1;
			}
		}
		if(flag==1)
			cout<<"Yes\n";
		else
			cout<<"No\n";

	}
}