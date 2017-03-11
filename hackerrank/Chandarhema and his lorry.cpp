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
    ll k,a[100000],result=0,modulo = 1000000007,ans=0;
    k = readInt();
    rep(i,0,k)
    {
        a[i] = readInt();
        result = a[i] ^ result;
    }
    if(result == 0)
    {
        ans = 1;
        rep(i,0,k-1)
        {
            ans = ans*2;
            ans = ans%modulo;
        }
        cout<<ans-1;
    }
    else
    {
        cout<<"0";
    }
    return 0;
}
