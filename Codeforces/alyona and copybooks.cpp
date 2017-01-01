#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
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
	ll n,a,b,c,minimum=100000000000;
	n=readInt();
	a=readInt();
	b=readInt();
	c=readInt();
	if(n%4==0)
	{
		cout<<"0";
	}
	else
	{
		n=4-(n%4);
		if(n==1)
		{
            minimum=min(a,c+b);
            minimum=min(minimum,(2*b)+a);
            cout<<minimum;
		}
		else if(n==2)
		{
		    minimum=min(b,2*a);
		    minimum=min(minimum,2*c);
            minimum=min(minimum,3*b);
            minimum=min((2*b)+(2*a),minimum);
            minimum=min(minimum,(b+c));
            cout<<minimum;
		}
		else
		{

			ll minimum=100000000000;
			minimum=min(a*3,c);
			minimum=min(minimum,(b+a));
			minimum=min(minimum,(2*c)+a);
			minimum=min(minimum,(3*b)+a);
			minimum=min(minimum,(c+2*b));
			minimum=min(minimum,(b+c+a));
			cout<<minimum;
		}
	}
    return 0;
}
