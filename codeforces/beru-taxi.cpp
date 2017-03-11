#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n,x1,y1,x[1000],y[1000],v[1000],i;
	float val=0.0,minimum=100000.0,val1,val2;
	cin>>x1>>y1;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x[i]>>y[i]>>v[i];
		val1=(abs(x1-x[i]))*(1.00);
		val2=(abs(y1-y[i]))*(1.00);
		val=float((val1+val2)/((1.00)*(v[i])));
		minimum=float(min(minimum,val));
	}
	cout<<setprecision(20)<<minimum;

}
