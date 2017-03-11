//template by chamow
//template
#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
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
    ll t,n,x[100001],y;
    int c;
    t = readInt();
    while(t--)
    {
        ll current,last;
        n = readInt();
        y = readInt();
        current = y;
        rep(i,1,n+1)
        {
            scanf("%c",&c);
            x[i] = readInt();
            if(c == 'T')
            {
                current = x[i];
            }
            else
            {
                current = x[i-1];
            }
        }

        cout<<current<<endl;
    }
    return 0;
}
