#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long i,n,k,a[100000],charged=0,actual=0;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		actual+=(a[i]);
	}
	cin>>charged;
	actual=actual-a[k];
	actual/=2;
	if(actual==charged)
	{
		cout<<"Bon Appetit";
	}
	else
	{
		cout<<charged-actual;
	}
}