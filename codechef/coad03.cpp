#include<bits/stdc++.h>

using namespace std;

int main()
{

	int t,n;
	long sum=0;
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n;
		if(n==1)
			{
				cout<<"1\n";
				continue;
			}
		while(n!=2 && n!=3)
		{
			sum+=(n%2);
			n/=2;
			sum+=(2);
		}
		cout<<sum+n<<'\n';
	}
}