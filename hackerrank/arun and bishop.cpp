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
    ll n,x,y,d1=0,d2=0,pairs = 0,c[1001],temp,a[1001][1001];
    n = readInt();
    c[0] = 0;
    c[1] = 0;
    rep(i,2,1001)
    {
        c[i] = c[i-1] + i-1;
        //cout<<c[i]<<" ";
    }
    temp = n;
    while(temp--)
    {
        x = readInt();
        y = readInt();
        a[x][y] = 1;


    }
    rep(i,1,1001)
    {
        rep(j,1,1001)
        {
            if(i==j)
            {
                if(a[i][j] == 1)
                {
                    ++d1;
                }
            }
            else if((i+j) == 1001
        }
    }
    cout<<d1<<d2;
    cout<<c[d1]+c[d2];

    return 0;
}
