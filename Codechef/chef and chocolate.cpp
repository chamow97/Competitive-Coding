#include<bits/stdc++.h>
using namespace std;

int main()
{
long long t,n,m;
cin>>t;
while(t--)
{
	cin>>n>>m;
	if(((n==1)&&(m==1))||(n==1 && m==3)||(m==1 && n==3)||(n==2 && m==2))
		cout<<"No\n";
	else
		cout<<"Yes\n";
}

}