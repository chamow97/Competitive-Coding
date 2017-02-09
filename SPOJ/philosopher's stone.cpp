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
    ll t;
     t = readInt();
        ll temp = t;

    while(t--)
    {
        ll t,h,w;
        ll a[205][205];
        ll counter = 0;

        ll maximum = -10;
        h = readInt();
        w = readInt();
         rep(i,0,h+1)
        {
            a[i][0] = 0;
        }
        rep(i,0,w+1)
        {
            a[0][i] = 0;
        }
        rep(i,0,h+1)
        {
            a[i][w+1] = 0;
        }
        rep(i,1,h+1)
        {
            rep(j,1,w+1)
            {
                a[i][j] = readInt();
            }
        }

        rep(i,1,h+1)
        {
            rep(j,1,w+1)
            {
                a[i][j] += max(a[i-1][j-1] , max(a[i-1][j+1],a[i-1][j]));

            }
        }
        rep(j,1,w+1)
        {
            maximum = max(maximum, a[h][j]);
        }
        cout<<maximum<<endl;
    }

    return 0;
}
