#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,a[51],minimum,maximum;
	int best;
	cin>>n;
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>a[i];
	}
	sort(a,a+m);
	best=10001;
	for(i=n-1;i<m;i++)
	{
		best=(min(best,a[i]-a[i-n+1]));
		
	}
	cout<<best;
}