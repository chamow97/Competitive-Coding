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
	string a,b;
	ll arr[27],brr[27],counter1=0,counter2=0;
	cin>>a>>b;
	bool sameString = false;
	ll len1 = a.length();
	ll len2 = b.length();
	counter1 = len1;
	counter2 = len2;
	if(len1 == len2)
	{
		rep(i,0,len1)
		{
		if(a[i]==b[i])
		{
			sameString = true;
		}
		else
		{
			sameString = false;
			break;
		}
		}
		if(sameString == true)
		{
			cout<<"-1";
		}
		else
		{
			cout<<max(len1,len2);
		}

	}
	else
	{
		cout<<max(len1,len2);
	}
	
	
    return 0;
}
