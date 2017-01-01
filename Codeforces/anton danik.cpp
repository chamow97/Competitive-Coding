#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,i,sum=0;
	char str[100001];
	cin>>n;
	cin>>str;
	for(i=0;i<n;i++)
	{
		if(str[i]=='A')
		{
			++sum;
		}
		else
		{
			--sum;
		}
	}
	if(sum>0)
	{
		cout<<"Anton";
	}
	else if(sum<0)
	{
		cout<<"Danik";
	}
	else
	{
		cout<<"Friendship";
	}

}