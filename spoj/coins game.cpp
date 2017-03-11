//template by chamow

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
	ll k,l,m;
	bool a[1000001];
	ll arr[51];
	k = readInt();
	l = readInt();
	m = readInt();
	a[0] = false;
	rep(i,1,1000001)
	{
		//a[i] = 0;
		if(i<k)
		{
			if(i%2 == 1)
			{
				a[i] = true;
			}
			else
			{
				a[i] = false;
			}
		}
		else if(i<l)
		{
			if(a[i-k]==false || a[i-1]==false)
			{
				a[i] = true;
			}
			else
			{
				a[i] = false;
			}
		}
		else
		{
			if(a[i-k]==false || a[i-l]==false || a[i-1]==false)
			{
				a[i] = true;
			}
			else
			{
				a[i] = false;
			}
		}
	}
	rep(i,0,m)
	{
		arr[i] = readInt();
	}
	rep(i,0,m)
	{
		if(a[arr[i]]==true)
		{
			cout<<"A";
		}
		else
		{
			cout<<"B";
		}
		//cout<<a[arr[i]]<<" ";
	}
	// rep(i,0,17){
	// 	cout<<a[i]<<" ";
	// }

    return 0;
}
