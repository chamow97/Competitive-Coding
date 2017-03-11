#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long x1,v1,x2,v2,value;
	float val;
	cin>>x1>>v1>>x2>>v2;
	if(v1==v2 && x1==x2)
		cout<<"YES";
	else if(v1==v2)
		cout<<"NO";
	else
	{val=((x2*1.00)-(x1*1.00))/((v1*1.00)-(v2*1.00));
	value=(x2-x1)/(v1-v2);
	if(value==val && val>=0.0)
		cout<<"YES";
	else
		cout<<"NO";
}

}