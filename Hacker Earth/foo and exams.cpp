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
    ll a,b,c,d,k,t,low,high,mid,func,pos;
    t = readInt();
    while(t--)
    {
        a = readInt();
        b = readInt();
        c = readInt();
        d = readInt();
        k = readInt();
        low = 0;
        pos = -1;
        high = pow(k,0.34);
        while(low <= high)
        {
            mid = (low + high )/2;
            func = ((a*pow(mid,3)) + (b*pow(mid,2)) + (c*mid) + d);
            if(func < k)
            {
                pos = mid;
                low = mid+1;
            }
            else if(func == k)
            {
                pos = mid;
                break;
            }
            else
            {
                high = mid - 1;
            }
        }
        if(pos == -1)
        {
            pos = 0;
        }
        cout<<pos<<endl;

    }
    return 0;
}
