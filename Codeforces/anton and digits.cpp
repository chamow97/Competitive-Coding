#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long k2,k3,k5,k6,val=0,mini=1000000000000;
	cin>>k2>>k3>>k5>>k6;
	mini = min(k2,mini);
	mini = min(k5,mini);
	mini = min(k6,mini);
	val+=(256*mini);
	k2=k2-mini;
	mini = min(k2,k3);
	val+=(mini*32);
	cout<<val;
}