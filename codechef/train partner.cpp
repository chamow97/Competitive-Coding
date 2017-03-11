#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
typedef long long ll;
ll readInt () {
	bool minus = false;
	ll result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
int main()
{
	ll t,n,temp;
	t=readInt();
	while(t--)
	{
		n=readInt();
		temp=n;
		temp=temp%8;
		if(temp == 1 || temp == 2 || temp == 3)
		{
			n+=3;
		}
		else if(temp == 4 || temp == 5 || temp ==6)
		{
			n-=3;
		}
		else if(temp == 7)
		{
			n+=1;
		}
		else if(temp == 0)
		{
			n-=1;
		}
		cout<<n;
		if(temp == 1 || temp ==4)
		{
			cout<<"LB";
		}
		else if(temp == 2 || temp ==5)
		{
			cout<<"MB";
		}
		else if(temp == 3 || temp == 6)
		{
			cout<<"UB";
		}
		else if(temp%8 == 0)
		{
			cout<<"SL";
		}
		else if(temp%7 == 0)
		{
			cout<<"SU";
		}
		cout<<endl;
	}
	return 0;
}
