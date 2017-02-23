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
    ll t,n,k,pos,a[100000];
    t = readInt();
    while(t--)
    {
        n = readInt();
        k = readInt();
        pos = readInt();
        rep(i,0,k)
        {
            a[i] = readInt();
        }
        sort(a,a+k);
        rep(i,0,k)
        {
            if(a[i] <= pos)
            {
                ++pos;
            }
            else
            {
                break;
            }
        }
        if(pos > n)
        {
            pos = -1;
        }
        printf("%lld \n", pos);
    }
    return 0;
}
