//template by chamow
//template
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
	ll c,d,l,t;
	t = readInt();
	while(t--)
	{
		c = readInt();
	d = readInt();
	l = readInt();
	if((c)>=2*d)
	{
		if(l<=((c+d)*4) && l>=(((c-(2*d))+d)*4) && l%4 == 0)
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
	else
	{
		if(l<=((c+d)*4) && l>=(d*4) && l%4 == 0)
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
	}
	
    return 0;
}
