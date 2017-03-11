#include<bits/stdc++.h>
using namespace std;
int main()
{
	bool isEqual=false,isAllDot=false;
	long long i,t,length;
	char a[123451];
	cin>>t;
	while(t--)
	{
		isAllDot=false;
		isEqual=false;
		cin>>a;
		length=strlen(a);
		for(i=0;i<length/2;i++)
		{
			if(a[i]=='.' && a[i]==a[length-1-i])
			{
				isAllDot=true;
			}
			else
			{
				isAllDot=false;
				break;
			}
		}
		if(length==1)
		{
			isEqual=true;
		}
		if(isAllDot==true)
		{
			for(i=0;i<length/2;i++)
			{
				a[i]='a';
				a[length-1-i]=a[i];
			}
			isEqual=true;
		}
		else if(isAllDot==false)
		{
			for(i=0;i<length/2;i++)
			{
			if(a[i]==a[length-1-i] && a[i]!='.')
			{
				isEqual=true;
			}			
			else if(a[i]=='.' && a[length-1-i]!='.')
			{
				a[i]=a[length-1-i];
				isEqual=true;
			}
			else if(a[i]!='.' && a[length-1-i]=='.')
			{
				a[length-1-i]=a[i];
				isEqual=true;
			}
			else if(a[i]=='.' && a[length-1-i]=='.')
			{
				a[i]='a';
				a[length-1-i]='a';	
			}
			else if(a[i]!=a[length-1-i] && a[i]!='.' && a[length-1-i]!='.')
			{
				isEqual=false;
				break;
			}

		}

		}
		
		if(isEqual==false)
			cout<<"-1\n";
		else
		{
			for(i=0;i<length/2;i++)
			{
				a[i]=a[length-1-i];
			}
			if(a[length/2]=='.')
				a[length/2]='a';
			cout<<a<<'\n';
		} 
	}
}