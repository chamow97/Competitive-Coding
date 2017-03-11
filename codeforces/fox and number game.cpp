#include<bits/stdc++.h>
using namespace std;
int gcd2(int a,int b)
{
	if(a==0)
		return b;
	else
		return gcd2(b%a,a);

}

int main()
{
	int i,j,n,a[100],gcdVal=0;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	gcdVal=a[0];
		for(j=1;j<n;j++)
		{
			gcdVal=gcd2(gcdVal,a[j]);
		}
	
	cout<<gcdVal*n;

}