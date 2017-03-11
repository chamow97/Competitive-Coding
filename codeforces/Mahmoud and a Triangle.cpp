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
	ll n,a[100000];
 	bool flag = false;
	n = readInt();
	rep(i,0,n)
	{
		a[i] = readInt();
	}
	sort(a,a+n);
	rep(i,1,n-1)
	{
		if((a[i] + a[i-1]) >a[i+1])
		{
			flag = true;
			break;
		}
	}
	if(flag == true)
	{

		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
    return 0;
}