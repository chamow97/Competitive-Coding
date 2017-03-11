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
    ll n,x,a[100001],b[200001],counter=0,temp;
    n = readInt();
    x = readInt();
    rep(i,1,n+1)
    {
        a[i] = readInt();
        b[a[i]]++;
    }
    rep(i,1,n+1)
    {
    	counter+=(b[a[i]^x]);
    	if(x == 0)
    	{
    		--counter;
    	}
    }
    cout<<(counter)/2;
    return 0;
}
