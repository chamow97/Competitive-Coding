#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long i,n,a[7],minimum=1000000000;
	char str[1000001];
	cin>>n;
	cin>>str;
	for(i=0;i<n;i++)
	{
		switch(str[i])
		{
			case 'h':a[0]++;
			break;
			case 'a':a[1]++;
			break;
			case 'c':a[2]++;
			break;
			case 'k':a[3]++;
			break;
			case 'e':a[4]++;
			break;
			case 'r':a[5]++;
			break;
			case 't':a[6]++;
			break;
		}
	}
	for(i=0;i<7;i++)
	{
		if(i==0 || i==1 || i==4 || i==5 )
		{
			minimum=min(minimum,a[i]/2);
		}
		else
		{
			minimum=min(minimum,a[i]);
		}
	}
	cout<<minimum;

	return 0;
}