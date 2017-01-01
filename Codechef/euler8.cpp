#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n,k,product=1,maximum=0;
	char a[1000];
	cin>>n>>k;
	cin>>a;
	for(i=0;i<n-k;i++)
	{
		product=1;
		for(j=i;j<k+i;j++)
		{
			product*=(a[j]-'0');
		}
		maximum=max(maximum,product);
	}
	cout<<maximum;
}