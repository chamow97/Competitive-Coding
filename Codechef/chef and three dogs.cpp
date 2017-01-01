#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t,s1,v1;
	double val=sqrt(7),total=0.0,time=0.0,s,v;
	cin>>t;
	while(t--)
	{
		cin>>s1>>v1;
		s=s1*1.0;
		v=v1*1.0;
		s=(2*s)/3;
		total=s/v;
		cout << setprecision(10) << fixed <<  total << '\n';
	}
}
