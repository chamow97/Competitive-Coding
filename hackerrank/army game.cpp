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
    ll n,m;
    n=readInt();
    m=readInt();
    if(n==1 && m==1 || n==1 && m==2 || n==2 && m==1 || n==2 && m==2)
    {
        cout<<"1";
    }
    else
    {
        n=(n+1)/2;
        m=(m+1)/2;
        cout<<n*m;
    }

    return 0;
}
