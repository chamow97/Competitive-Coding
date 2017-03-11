#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long temp,t,a,b,d,e,f,g,h;
	cin>>t;
	while(t--)
	{
		
		cin>>a>>b;
		if(b==0)
			cout<<"1\n";
		else
		{
			d=pow(a,1);
			e=pow(a,2);
			f=pow(a,3);
			g=pow(a,4);
			h=pow(a,5);
			if((e%10)==(d%10))
			{
				temp=b%1;
				if(temp==0)
					temp=1;
			}
			else if((d%10)==(f%10))
			{
				temp=b%2;
				if(temp==0)
					temp=2;
				
			}
			else if((d%10)==(g%10))
			{
				temp=b%3;
				if(temp==0)
					temp=3;
			}
			else if((d%10)==(h%10))
			{
				temp=b%4;
				if(temp==0)
					temp=4;
			}
			d=pow(a,temp);
			cout<<d%10<<'\n';
		}
	}	
}
