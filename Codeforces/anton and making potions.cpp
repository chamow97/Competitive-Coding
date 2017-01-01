#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(i=0;i<n;i++)
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
    int i=0,n=10;
    rep(i,n)
    {
        cout<<i<<' ';
    }
}
