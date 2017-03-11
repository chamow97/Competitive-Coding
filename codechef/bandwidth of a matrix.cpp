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
    ll n,t,a[501][501],ones = 0, bandwidth = 0, temp;
    t = readInt();
    while(t--)
    {
        temp = 2;
        bandwidth = 0;
        ones = 0;
        n = readInt();
        rep(i,0,n)
        {
            rep(j,0,n)
            {
                a[i][j] = readInt();
                if(a[i][j] == 1)
                {
                    ++ones;
                }
            }
        }
        if(ones <= n)
        {
            bandwidth = 0;
        }
        else
        {
            ones -= n;
            while(ones > 0)
            {

                ones = ones - ((2*n) - temp);
                ++bandwidth;
                temp += 2;
            }
        }
        cout<<bandwidth<<endl;

    }
    return 0;
}

