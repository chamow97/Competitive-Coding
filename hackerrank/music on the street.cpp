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
    ll n,a[1000000],hmin,hmax,m,i,counter1=0,counter2=0,start=0;
    n=readInt();
    rep(i,0,n)
    {
        a[i]=readInt();
    }
    m=readInt();
    hmin=readInt();
    hmax=readInt();
    rep(i,1,n)
    {
        if(a[i]-a[i-1]>hmax)
        {
            b[k++]=a[i];
        }
    }
    return 0;
}
