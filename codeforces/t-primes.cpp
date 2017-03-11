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
    ll n,a[100000];
    n = readInt();
    rep(i,0,n)
    {
        a[i] = readInt();
    }
    rep(i,0,n)
    {
        ll sum = 0;
         rep(j,1,sqrt(a[i])+1)
        {
            if( a[i]%j == 0)
            {
                if(j == a[i]/j)
                {
                    sum += 1;
                }
                else
                {
                    sum += 2;
                }
            }
        }
        //cout<<sum<<endl;
        if(sum == 3)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}