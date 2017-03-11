#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long t,s,x,val1=0,val2=0;
	cin>>t>>s>>x;
	val1+=t;
	val2+=t;
	while(val1<x && val2<x)
	{
		val1+=s;
		val2+=(val1+1);
	}
	if(val1==x || val2==x)
		cout<<"YES";
	else
		cout<<"NO";

}